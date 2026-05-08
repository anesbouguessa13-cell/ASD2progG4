#include <stdio.h>
#include "include/array.h"
//#include "include/linked_list.h"
//#include "include/stack.h"
//#include "include/queue.h"
//#include "include/file_utils.h"
#include "include/string_utils.h"
#include<string.h>
#include <stdlib.h>

// 1. MOVE MACROS OUTSIDE: Macros should be global, not inside a function.





void arrayMenu() {
    // Variable Declarations
    int arr[MAX_1D], size = 0;
    int matA[MAX_ROWS][MAX_COLS], matB[MAX_ROWS][MAX_COLS], matRes[MAX_ROWS][MAX_COLS];
    int rowsA = 0, colsA = 0, rowsB = 0, colsB = 0;
    int *dynArr = NULL;
    int dynSize = 0, dynCapacity = 0;
    
    int choice, subChoice, val, idx, k;

    while (1) {
        printf("\n--- ARRAY & MATRIX MASTER MENU ---\n");
        printf("1. Basic Array Ops (Init, Print, Insert, Delete)\n");
        printf("2. Search & Sort (Linear, Binary, Bubble, etc.)\n");
        printf("3. Array Stats (Max, Min, Sum, Avg, Reverse, Rotate)\n");
        printf("4. Matrix Operations (Add, Multiply, Transpose)\n");
        printf("5. Dynamic Array Operations\n");
        printf("0. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1: // Basic Ops
                printf("1. Init  2. Print  3. Insert  4. Delete: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    initArray(arr, &size);
                    printf("Array initialized.\n");
                } else if (subChoice == 2) {
                    printArray(arr, size);
                } else if (subChoice == 3) {
                    printf("Enter index and value: ");
                    scanf("%d %d", &idx, &val);
                    if (insertAt(arr, &size, idx, val) == 0) printf("Inserted.\n");
                    else printf("Failed to insert.\n");
                } else if (subChoice == 4) {
                    printf("Enter index to delete: ");
                    scanf("%d", &idx);
                    if (deleteAt(arr, &size, idx) == 0) printf("Deleted.\n");
                    else printf("Invalid index.\n");
                }
                break;

            case 2: // Search & Sort
                printf("1. Linear Search 2. Binary Search 3. Bubble Sort 4. Selection Sort 5. Insertion Sort 6. Merge Sort 7. Quick Sort: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    printf("Value: "); scanf("%d", &val);
                    printf("Found at index: %d\n", linearSearch(arr, size, val));
                } else if (subChoice == 2) {
                    printf("Value (ensure array is sorted!): "); scanf("%d", &val);
                    printf("Found at index: %d\n", binarySearch(arr, size, val));
                } else if (subChoice == 3) bubbleSort(arr, size);
                else if (subChoice == 4) selectionSort(arr, size);
                else if (subChoice == 5) insertionSort(arr, size);
                else if (subChoice == 6) mergeSort(arr, 0, size - 1);
                else if (subChoice == 7) quickSort(arr, 0, size - 1);
                if (subChoice >= 3) printf("Operation complete.\n");
                break;

            case 3: // Stats & Transformations
                printf("1. Max/Min 2. Sum/Avg 3. Reverse 4. Rotate Left: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) printf("Max: %d, Min: %d\n", findMax(arr, size), findMin(arr, size));
                else if (subChoice == 2) printf("Sum: %d, Avg: %.2f\n", sumArray(arr, size), averageArray(arr, size));
                else if (subChoice == 3) { reverseArray(arr, size); printArray(arr, size); }
                else if (subChoice == 4) {
                    printf("Steps (k): "); scanf("%d", &k);
                    rotateLeft(arr, size, k);
                    printArray(arr, size);
                }
                break;

            case 4: // Matrices
                printf("1. Init Matrix A 2. Print A 3. Transpose A 4. Add (A+B) 5. Multiply (Square): ");
                scanf("%d", &subChoice);
                if (subChoice == 1) initMatrix(matA, &rowsA, &colsA);
                else if (subChoice == 2) printMatrix(matA, rowsA, colsA);
                else if (subChoice == 3) {
                    transposeMatrix(matA, rowsA, colsA, matRes);
                    printMatrix(matRes, colsA, rowsA);
                } else if (subChoice == 4) {
                    printf("Init Matrix B:\n");
                    initMatrix(matB, &rowsB, &colsB);
                    if (rowsA == rowsB && colsA == colsB) {
                        addMatrices(matA, matB, matRes, rowsA, colsA);
                        printMatrix(matRes, rowsA, colsA);
                    } else printf("Size mismatch!\n");
                } else if (subChoice == 5) {
                    printf("Dimension n for square multiplication: "); scanf("%d", &val);
                    multiplyMatrices(matA, matB, matRes, val);
                    printMatrix(matRes, val, val);
                }
                break;

            case 5: // Dynamic Array
                printf("1. Create 2. Fill 3. Resize 4. Free: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    printf("Capacity: "); scanf("%d", &dynCapacity);
                    dynArr = createDynamicArray(dynCapacity);
                } else if (subChoice == 2) {
                    printf("How many elements: "); scanf("%d", &dynSize);
                    fillArray(dynArr, dynSize);
                } else if (subChoice == 3) {
                    printf("New Capacity: "); scanf("%d", &dynCapacity);
                    dynArr = resizeArray(dynArr, dynCapacity);
                } else if (subChoice == 4) {
                    freeArray(dynArr);
                    dynArr = NULL;
                    printf("Memory freed.\n");
                }
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}


   

#define MAX 1024

void string_utils_menu() {
    char str[MAX], other[MAX], result[MAX];
    int choice, n, start, len;
    char c;

    while (1) {
        printf("\n--- STRING UTILITIES MENU ---\n");
        printf("1. Length (strlen)         9. Reverse String\n");
        printf("2. Copy (strcpy)          10. Count Vowels\n");
        printf("3. N-Copy (strncpy)       11. Count Words\n");
        printf("4. Concatenate (strcat)   12. Check Palindrome\n");
        printf("5. Compare (strcmp)       13. Remove Character\n");
        printf("6. N-Compare (strncmp)    14. Remove Spaces\n");
        printf("7. To Upper Case          15. Extract Substring\n");
        printf("8. To Lower Case          16. Compare (Ignore Case)\n");
        printf("0. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline buffer

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Length: %d\n", my_strlen(str));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                my_strcpy(result, str);
                printf("Copied string: %s\n", result);
                break;

            case 3:
                printf("Enter source: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter N: "); scanf("%d", &n);
                my_strncpy(result, str, n);
                result[n] = '\0'; // Ensure safety
                printf("N-Copied: %s\n", result);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter string to append: ");
                fgets(other, MAX, stdin); other[strcspn(other, "\n")] = 0;
                my_strcat(str, other);
                printf("Result: %s\n", str);
                break;

            case 5:
                printf("Enter String A: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter String B: ");
                fgets(other, MAX, stdin); other[strcspn(other, "\n")] = 0;
                printf("Comparison result: %d\n", my_strcmp(str, other));
                break;

            case 7:
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                toUpperCase(str);
                printf("Uppercase: %s\n", str);
                break;

            case 9:
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                reverseString(str);
                printf("Reversed: %s\n", str);
                break;

            case 11:
                printf("Enter sentence: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Word count: %d\n", countWords(str));
                break;

            case 12:
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                if (isPalindrome(str)) printf("It is a palindrome.\n");
                else printf("Not a palindrome.\n");
                break;

            case 13:
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter character to remove: ");
                scanf(" %c", &c);
                removeChar(str, c);
                printf("Result: %s\n", str);
                break;

            case 15:
                printf("Enter source string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter start index and length: ");
                scanf("%d %d", &start, &len);
                substring(str, start, len, result);
                printf("Substring: %s\n", result);
                break;

            case 16:
                printf("Enter String A: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter String B: ");
                fgets(other, MAX, stdin); other[strcspn(other, "\n")] = 0;
                printf("Comparison (Ignore Case): %d\n", compareIgnoreCase(str, other));
                break;

            default:
                printf("Feature not yet implemented or invalid choice.\n");
        }
    }
}
 


int main() {
    int choice;
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Linked Lists\n3. Stacks\n"
               "4. Queues\n5. File Handling\n6. String Utils\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arrayMenu(); break;
            case 6: string_utils();break;
        }
    } while (choice != 0);
    return 0;
}

