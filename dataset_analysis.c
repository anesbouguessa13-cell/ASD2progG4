#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "include/common.h" // Fixed path to match the root folder location

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
int loadDataset(const char* filename, Record arr[], int* count);
void displayDataset(Record arr[], int count);
void sortDatasetByField(Record arr[], int count, char* field);
Record findMaxByField(Record arr[], int count);
Record findMinByField(Record arr[], int count);
float averageByField(Record arr[], int count);
int filterByCondition(Record arr[], int count, float threshold, Record out[]);
int saveBinaryReport(const char* filename, Record arr[], int count);
void datasetAnalysisMenu();

// ============================================================================
// CORE DATA COMPUTATION LOGIC
// ============================================================================

int loadDataset(const char* filename, Record arr[], int* count) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        *count = 0;
        return -1;
    }
    
    int i = 0;
    while (i < MAX_1D && fread(&arr[i], sizeof(Record), 1, fp) == 1) {
        i++;
    }
    
    *count = i;
    fclose(fp);
    return 0;
}

void displayDataset(Record arr[], int count) {
    if (count == 0) {
        printf("\nNo data currently loaded into the active analysis buffer.\n");
        return;
    }
    
    printf("\n%-6s %-10s %-25s %-12s %-15s\n", "Index", "ID", "Name", "Score", "Category");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("[%-4d] %-10d %-25s %-12.2f %-15s\n", 
               i, arr[i].id, arr[i].name, arr[i].score, arr[i].category);
    }
    printf("--------------------------------------------------------------------\n");
}

void sortDatasetByField(Record arr[], int count, char* field) {
    if (count <= 1) return;
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int shouldSwap = 0;
            
            if (strcmp(field, "id") == 0) {
                if (arr[j].id > arr[j + 1].id) shouldSwap = 1;
            } else if (strcmp(field, "score") == 0) {
                if (arr[j].score > arr[j + 1].score) shouldSwap = 1;
            } else if (strcmp(field, "name") == 0) {
                if (strcmp(arr[j].name, arr[j + 1].name) > 0) shouldSwap = 1;
            }
            
            if (shouldSwap) {
                Record temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

Record findMaxByField(Record arr[], int count) {
    Record maxRecord = { -1, "None", -FLT_MAX, "None" };
    if (count == 0) return maxRecord;
    
    maxRecord = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i].score > maxRecord.score) {
            maxRecord = arr[i];
        }
    }
    return maxRecord;
}

Record findMinByField(Record arr[], int count) {
    Record minRecord = { -1, "None", FLT_MAX, "None" };
    if (count == 0) return minRecord;
    
    minRecord = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i].score < minRecord.score) {
            minRecord = arr[i];
        }
    }
    return minRecord;
}

float averageByField(Record arr[], int count) {
    if (count == 0) return 0.0f;
    
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += arr[i].score;
    }
    return sum / (float)count;
}

int filterByCondition(Record arr[], int count, float threshold, Record out[]) {
    int matchCount = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i].score > threshold) {
            out[matchCount] = arr[i];
            matchCount++;
        }
    }
    return matchCount;
}

int saveBinaryReport(const char* filename, Record arr[], int count) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return -1;
    
    size_t written = fwrite(arr, sizeof(Record), count, fp);
    fclose(fp);
    
    return (written == (size_t)count) ? 0 : -1;
}

// ============================================================================
// INTERACTIVE ENGINE MENU MODULE
// ============================================================================
void datasetAnalysisMenu() {
    const char* sourceFile = "records.dat";
    const char* reportFile = "analysis_report.dat";
    
    Record dataArray[MAX_1D];
    Record filteredArray[MAX_1D];
    int count = 0;
    int filteredCount = 0;
    
    int choice;
    char fieldSelection[20];
    float thresholdVal;

    while (1) {
        printf("\n=========================================\n");
        printf("      DATA ANALYSIS CORE ENGINE          \n");
        printf("=========================================\n");
        printf(" Active Source Target: %s\n", sourceFile);
        printf(" Loaded Track Count  : %d Elements\n", count);
        printf("-----------------------------------------\n");
        printf("  1. Load Dataset Matrix from Binary File\n");
        printf("  2. Display Loaded Dataset Array Table\n");
        printf("  3. Sort Dataset Array via Named Field\n");
        printf("  4. View Summary Statistics (Max/Min/Avg)\n");
        printf("  5. Filter Elements Above Score Threshold\n");
        printf("  6. Export Current Array State to Report File\n");
        printf("-----------------------------------------\n");
        printf("  0. Back to Main Module Menu\n");
        printf("=========================================\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection format.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
            case 1:
                if (loadDataset(sourceFile, dataArray, &count) == 0) {
                    printf("Success! Loaded %d active records into program memory.\n", count);
                } else {
                    printf("Error loading file track. Check if binary file exists.\n");
                }
                break;

            case 2:
                displayDataset(dataArray, count);
                break;

            case 3:
                if (count == 0) {
                    printf("Array buffer is empty. Load data parameters first.\n");
                    break;
                }
                printf("Enter sort field name exactly ('id', 'name', or 'score'): ");
                scanf("%19s", fieldSelection);
                if (strcmp(fieldSelection, "id") == 0 || strcmp(fieldSelection, "name") == 0 || strcmp(fieldSelection, "score") == 0) {
                    sortDatasetByField(dataArray, count, fieldSelection);
                    printf("Dataset array successfully organized via key field '%s'.\n", fieldSelection);
                } else {
                    printf("Invalid field choice descriptor.\n");
                }
                break;

            case 4:
                if (count == 0) {
                    printf("No items in buffer to evaluate data matrix calculations.\n");
                } else {
                    Record maxR = findMaxByField(dataArray, count);
                    Record minR = findMinByField(dataArray, count);
                    float avgVal = averageByField(dataArray, count);
                    
                    printf("\n=== CALCULATED STATISTICAL SUMMARY ===\n");
                    printf(" Maximum Record : ID: %d | Name: %-15s | Score: %.2f\n", maxR.id, maxR.name, maxR.score);
                    printf(" Minimum Record : ID: %d | Name: %-15s | Score: %.2f\n", minR.id, minR.name, minR.score);
                    printf(" Average Score Evaluation Value  : %.2f\n", avgVal);
                }
                break;

            case 5:
                if (count == 0) {
                    printf("No data points available to apply filtering criteria.\n");
                    break;
                }
                printf("Enter minimum evaluation score threshold cutoff limit: ");
                scanf("%f", &thresholdVal);
                filteredCount = filterByCondition(dataArray, count, thresholdVal, filteredArray);
                printf("\n--- Filter Screening Output (Score > %.2f) ---\n", thresholdVal);
                displayDataset(filteredArray, filteredCount);
                break;

            case 6:
                if (count == 0) {
                    printf("No items currently tracked inside buffer to save.\n");
                    break;
                }
                if (saveBinaryReport(reportFile, dataArray, count) == 0) {
                    printf("Successfully exported array tracks to binary report file: '%s'\n", reportFile);
                } else {
                    printf("Error writing to file. Snapshot report generation failed.\n");
                }
                break;

            default:
                printf("Selection outside valid tracking operational indexes. Try again.\n");
        }
    }
}