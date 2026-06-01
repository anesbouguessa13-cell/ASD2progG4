#include <stdio.h>
#include "include/array.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/file_utils.h"
#include "include/string_utils.h"
#include<string.h>
#include <stdlib.h>







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

void string_utils() {
   
    char str[MAX], other[MAX], result[MAX];
    int choice, n, start, len;
    char c;

    do {
        printf("\n--- STRING UTILITIES MENU ---\n");
        printf("1. Length (strlen)\n2. Copy (strcpy)\n3. N-Copy (strncpy)\n4. Concatenate (strcat)\n");
        printf("5. Compare (strcmp)\n7. To Upper Case\n9. Reverse String\n");
        printf("11. Count Words\n12. Check Palindrome\n13. Remove Character\n");
        printf("15. Extract Substring\n16. Compare (Ignore Case)\n0. Exit\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) break;
        while (getchar() != '\n'); // CRITICAL: Clears the buffer so fgets works

        switch (choice) {
            case 1: {
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                int l = my_strlen(str);
                printf("RESULT: The length is %d\n", l); // Added explicit print
                break;
            }
            case 2: {
                printf("Enter source string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                my_strcpy(result, str);
                printf("RESULT: Copied string is [%s]\n", result);
                break;
            }
            case 3: {
                printf("Enter source: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter N: "); scanf("%d", &n);
                my_strncpy(result, str, n);
                result[n] = '\0'; 
                printf("RESULT: N-Copied string: %s\n", result);
                break;
            }
            case 4: {
                printf("Enter base string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Enter string to append: ");
                fgets(other, MAX, stdin); other[strcspn(other, "\n")] = 0;
                my_strcat(str, other);
                printf("RESULT: Combined string: %s\n", str);
                break;
            }
            case 5: {
                printf("String A: "); fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("String B: "); fgets(other, MAX, stdin); other[strcspn(other, "\n")] = 0;
                printf("RESULT: Comparison value: %d\n", my_strcmp(str, other));
                break;
            }
            case 7: {
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                toUpperCase(str);
                printf("RESULT: Uppercase version: %s\n", str);
                break;
            }
            case 9: {
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                reverseString(str);
                printf("RESULT: Reversed string: %s\n", str);
                break;
            }
            case 11: {
                printf("Enter sentence: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("RESULT: Total words: %d\n", countWords(str));
                break;
            }
            case 12: {
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                if (isPalindrome(str)) printf("RESULT: It IS a palindrome.\n");
                else printf("RESULT: It is NOT a palindrome.\n");
                break;
            }
            case 13: {
                printf("Enter string: ");
                fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Char to remove: "); scanf(" %c", &c);
                removeChar(str, c);
                printf("RESULT: String after removal: %s\n", str);
                break;
            }
            case 15: {
                printf("Source: "); fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("Start index and length: "); scanf("%d %d", &start, &len);
                substring(str, start, len, result);
                printf("RESULT: Substring: %s\n", result);
                break;
            }
            case 16: {
                printf("String A: "); fgets(str, MAX, stdin); str[strcspn(str, "\n")] = 0;
                printf("String B: "); fgets(other, MAX, stdin); other[strcspn(other, "\n")] = 0;
                printf("RESULT: Case-insensitive diff: %d\n", compareIgnoreCase(str, other));
                break;
            }
        }
    } while (choice != 0);
}



void linkedListMenu() {
    ArrayList sll;
    DLL dll;
    initList(&sll);
    initListDLL(&dll);

    int choice, val, pos, res;

    while (1) {
        printf("\n=========================================\n");
        printf("    CURSOR-BASED LINKED LIST MENU        \n");
        printf("=========================================\n");
        printf(" [ArrayList (Singly Linked Layout)]\n");
        printf("  1. Insert at Beginning    2. Insert at End\n");
        printf("  3. Insert at Position     4. Delete from Beginning\n");
        printf("  5. Delete from End        6. Delete by Value\n");
        printf("  7. Search for Value       8. Display List\n");
        printf("  9. Reverse List          10. Bubble Sort List\n");
        printf("-----------------------------------------\n");
        printf(" [Doubly Linked Array Layout (DLL)]\n");
        printf(" 11. Insert DLL Start      12. Insert DLL End\n");
        printf(" 13. Delete DLL by Value   14. Display DLL Forward\n");
        printf(" 15. Display DLL Backward\n");
        printf("-----------------------------------------\n");
        printf("  0. Back to Main Module Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting Linked List Module.\n");
            break;
        }

        switch (choice) {
            /* --- SLL Array Operations --- */
            case 1:
                printf("Enter value to insert at start: ");
                scanf("%d", &val);
                if (insertBeginning(&sll, val) == 0) printf("Successfully inserted %d.\n", val);
                else printf("Error: Array storage structure full.\n");
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                if (insertEnd(&sll, val) == 0) printf("Successfully inserted %d.\n", val);
                else printf("Error: Array storage structure full.\n");
                break;

            case 3:
                printf("Enter position (0 to %d) and value: ", sll.size);
                scanf("%d %d", &pos, &val);
                if (insertAtPosition(&sll, pos, val) == 0) printf("Successfully inserted %d at position %d.\n", val, pos);
                else printf("Error: Invalid position index or list structure full.\n");
                break;

            case 4:
                res = deleteBeginning(&sll);
                if (res != -1) printf("Deleted value: %d\n", res);
                else printf("List is already empty.\n");
                break;

            case 5:
                res = deleteEnd(&sll);
                if (res != -1) printf("Deleted value: %d\n", res);
                else printf("List is already empty.\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                if (deleteByValue(&sll, val) == 0) printf("Successfully deleted %d.\n", val);
                else printf("Value %d not found or list empty.\n", val);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &val);
                res = searchValue(&sll, val);
                if (res != -1) printf("Value found at internal array index slot: %d\n", res);
                else printf("Value %d not found in storage tracks.\n", val);
                break;

            case 8:
                printf("SLL Current State: ");
                displayList(&sll);
                break;

            case 9:
                reverseList(&sll);
                printf("List links reversed. New structure track: ");
                displayList(&sll);
                break;

            case 10:
                sortListBubble(&sll);
                printf("List bubble sorted. New structure track: ");
                displayList(&sll);
                break;

            /* --- DLL Array Operations --- */
            case 11:
                printf("Enter value to insert at DLL start: ");
                scanf("%d", &val);
                if (insertBeginningDLL(&dll, val) == 0) printf("Successfully inserted %d into DLL tracker.\n", val);
                else printf("Error: Array storage structure full.\n");
                break;

            case 12:
                printf("Enter value to insert at DLL end: ");
                scanf("%d", &val);
                if (insertEndDLL(&dll, val) == 0) printf("Successfully inserted %d into DLL tracker.\n", val);
                else printf("Error: Array storage structure full.\n");
                break;

            case 13:
                printf("Enter value to delete from DLL: ");
                scanf("%d", &val);
                if (deleteByValueDLL(&dll, val) == 0) printf("Successfully deleted %d from DLL storage matrix.\n", val);
                else printf("Value %d not found in DLL tracks.\n", val);
                break;

            case 14:
                printf("DLL Forward Display: ");
                displayForward(&dll);
                break;

            case 15:
                printf("DLL Backward Display: ");
                displayBackward(&dll);
                break;

            default:
                printf("Invalid selection option. Try again.\n");
        }
    }
}

void stackMenu() {
    Stack s;
    initStack(&s);

    int choice, val, res;

    while (1) {
        printf("\n=========================================\n");
        printf("        STACK OPERATIONS MENU (ARRAY)    \n");
        printf("=========================================\n");
        printf("  1. Push (Insert Element)\n");
        printf("  2. Pop (Remove Element)\n");
        printf("  3. Peek (Inspect Top Element)\n");
        printf("  4. Check if Empty\n");
        printf("  5. Check if Full\n");
        printf("  6. Display Stack State\n");
        printf("-----------------------------------------\n");
        printf("  0. Back to Main Module Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting Stack Module.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push onto stack: ");
                scanf("%d", &val);
                if (push(&s, val) == 0) {
                    printf("Successfully pushed %d onto the stack.\n", val);
                } else {
                    printf("Stack Overflow! Cannot push %d, stack is full.\n", val);
                }
                break;

            case 2:
                res = pop(&s);
                if (res != INT_MIN) {
                    printf("Popped value: %d\n", res);
                } else {
                    printf("Stack Underflow! The stack is empty.\n");
                }
                break;

            case 3:
                res = peek(&s);
                if (res != INT_MIN) {
                    printf("Top element is: %d\n", res);
                } else {
                    printf("Stack is empty. Nothing to peek.\n");
                }
                break;

            case 4:
                if (isEmpty(&s)) {
                    printf("The stack is currently EMPTY.\n");
                } else {
                    printf("The stack is NOT empty (%d element(s) inside).\n", s.top + 1);
                }
                break;

            case 5:
                if (isFull(&s)) {
                    printf("The stack is currently FULL.\n");
                } else {
                    printf("The stack is NOT full (%d/%d slots used).\n", s.top + 1, MAX_STACK_SIZE);
                }
                break;

            case 6:
                if (isEmpty(&s)) {
                    printf("Stack [ ] <- Top (Empty)\n");
                } else {
                    printf("Stack content (Top to Bottom):\n");
                    for (int i = s.top; i >= 0; i--) {
                        if (i == s.top) {
                            printf(" [%d] <- Top\n", s.data[i]);
                        } else {
                            printf(" [%d]\n", s.data[i]);
                        }
                    }
                }
                break;

            default:
                printf("Invalid selection option. Try again.\n");
        }
    }
}
void queueMenu() {
    Queue q;
    initQueue(&q);

    int choice, val, res;

    while (1) {
        printf("\n=========================================\n");
        printf("    QUEUE OPERATIONS MENU (CIRCULAR)     \n");
        printf("=========================================\n");
        printf("  1. Enqueue (Insert Element at Rear)\n");
        printf("  2. Dequeue (Remove Element from Front)\n");
        printf("  3. Peek Front Element\n");
        printf("  4. Peek Rear Element\n");
        printf("  5. Check Status (Empty / Full / Size)\n");
        printf("  6. Display Queue State\n");
        printf("-----------------------------------------\n");
        printf("  0. Back to Main Module Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting Queue Module.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                if (enqueue(&q, val) == 0) {
                    printf("Successfully enqueued %d.\n", val);
                } else {
                    printf("Queue Overflow! Cannot enqueue %d, queue is full.\n", val);
                }
                break;

            case 2:
                res = dequeue(&q);
                if (res != INT_MIN) {
                    printf("Dequeued value: %d\n", res);
                } else {
                    printf("Queue Underflow! The queue is empty.\n");
                }
                break;

            case 3:
                res = front(&q);
                if (res != INT_MIN) {
                    printf("Front element is: %d\n", res);
                } else {
                    printf("Queue is empty. No front element.\n");
                }
                break;

            case 4:
                res = rear(&q);
                if (res != INT_MIN) {
                    printf("Rear element is: %d\n", res);
                } else {
                    printf("Queue is empty. No rear element.\n");
                }
                break;

            case 5:
                printf("Queue status:\n");
                printf("  - Count: %d / %d slots used.\n", q.count, MAX_QUEUE_SIZE);
                printf("  - Status: %s\n", (q.count == 0) ? "EMPTY" : (q.count == MAX_QUEUE_SIZE) ? "FULL" : "AVAILABLE");
                printf("  - Front index: %d, Rear index: %d\n", q.front, q.rear);
                break;

            case 6:
                if (q.count == 0) {
                    printf("Queue: [ Empty ]\n");
                } else {
                    printf("Queue elements from Front to Rear:\n");
                    printf("Front -> ");
                    for (int i = 0; i < q.count; i++) {
                        int index = (q.front + i) % MAX_QUEUE_SIZE;
                        printf("[%d] ", q.data[index]);
                    }
                    printf("<- Rear\n");
                }
                break;

            default:
                printf("Invalid selection option. Try again.\n");
        }
    }
}
void fileMenu() {
    const char* defaultFile = "records.dat";
    const char* backupFile = "records_backup.dat";
    
    int choice, val, res;
    Record r;

    while (1) {
        printf("\n=========================================\n");
        printf("       BINARY FILE OPERATIONS MENU       \n");
        printf("=========================================\n");
        printf(" Current active file: %s\n", defaultFile);
        printf("-----------------------------------------\n");
        printf("  1. Create / Clear Binary File\n");
        printf("  2. Write / Append New Record\n");
        printf("  3. Read Record by Index Position\n");
        printf("  4. Count Total Records inside File\n");
        printf("  5. Search for Record by ID\n");
        printf("  6. Update Existing Record by Index\n");
        printf("  7. Backup Data (Copy to %s)\n", backupFile);
        printf("  8. Print All Records (View File)\n");
        printf("-----------------------------------------\n");
        printf("  0. Back to Main Module Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting File I/O Module.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (createBinaryFile(defaultFile) == 0) {
                    printf("Successfully created/truncated binary storage file '%s'.\n", defaultFile);
                } else {
                    printf("Error: Could not create binary storage file.\n");
                }
                break;

            case 2:
                printf("\n--- Enter Record Data ---\n");
                printf("ID: "); scanf("%d", &r.id);
                printf("Name (no spaces): "); scanf("%49s", r.name);
                printf("Score: "); scanf("%f", &r.score);
                printf("Category: "); scanf("%19s", r.category);

                if (appendRecord(defaultFile, &r) == 0) {
                    printf("Record successfully written to file.\n");
                } else {
                    printf("Error: Failed to write record data.\n");
                }
                break;

            case 3:
                printf("Enter target record index position to read: ");
                scanf("%d", &val);
                if (readRecord(defaultFile, val, &r) == 0) {
                    printf("\n[Record at Index %d]\n", val);
                    printf("ID:       %d\n", r.id);
                    printf("Name:     %s\n", r.name);
                    printf("Score:    %.2f\n", r.score);
                    printf("Category: %s\n", r.category);
                } else {
                    printf("Error: Index position out of range or file unreadable.\n");
                }
                break;

            case 4:
                res = countRecords(defaultFile);
                if (res >= 0) {
                    printf("Total valid records inside file: %d\n", res);
                } else {
                    printf("Could not open file, or file does not exist yet.\n");
                }
                break;

            case 5:
                printf("Enter target ID number to find: ");
                scanf("%d", &val);
                res = searchRecordById(defaultFile, val, &r);
                if (res != -1) {
                    printf("Record Found at File Index Location: %d\n", res);
                    printf(" -> ID: %d | Name: %s | Score: %.2f | Cat: %s\n", r.id, r.name, r.score, r.category);
                } else {
                    printf("No record matching ID %d found.\n", val);
                }
                break;

            case 6:
                printf("Enter index position to update: ");
                scanf("%d", &val);
                
                // Confirm entry exists first
                if (readRecord(defaultFile, val, &r) != 0) {
                    printf("Error: Index location invalid. Cannot overwrite nonexistent data.\n");
                    break;
                }
                
                printf("Current details: ID: %d, Name: %s\n", r.id, r.name);
                printf("\n--- Enter NEW Data for this position ---\n");
                printf("New ID: "); scanf("%d", &r.id);
                printf("New Name (no spaces): "); scanf("%49s", r.name);
                printf("New Score: "); scanf("%f", &r.score);
                printf("New Category: "); scanf("%19s", r.category);

                if (updateRecord(defaultFile, val, &r) == 0) {
                    printf("Record at index %d successfully altered.\n", val);
                } else {
                    printf("Error performing binary update instruction.\n");
                }
                break;

            case 7:
                if (copyBinaryFile(defaultFile, backupFile) == 0) {
                    printf("Backup operation successful. Created clone layout inside '%s'.\n", backupFile);
                } else {
                    printf("Error copying source tracks over to target.\n");
                }
                break;

            case 8:
                res = countRecords(defaultFile);
                if (res <= 0) {
                    printf("File is empty or missing. Add a record first!\n");
                } else {
                    printf("\n%-6s %-15s %-8s %-15s\n", "Index", "ID (Name)", "Score", "Category");
                    printf("----------------------------------------------------\n");
                    for (int i = 0; i < res; i++) {
                        if (readRecord(defaultFile, i, &r) == 0) {
                            char idNameBuf[65];
                            sprintf(idNameBuf, "%d (%s)", r.id, r.name);
                            printf("[%-4d] %-15s %-8.2f %-15s\n", i, idNameBuf, r.score, r.category);
                        }
                    }
                }
                break;

            default:
                printf("Invalid selection option. Try again.\n");
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
            case 2: linkedListMenu() ;break;
            case 3: stackMenu(); break;
            case 4: queueMenu();break;
            case 5: fileMenu();break;
            case 6: string_utils();break;
        }
    } while (choice != 0);
    return 0;
}

