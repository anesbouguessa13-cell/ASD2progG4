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


void arrayMenu(){
    

// 1. MOVE MACROS OUTSIDE: Macros should be global, not inside a function.
#define MAX_SIZE 100
#define MAX_COLS 100


    int arr[MAX_SIZE], size = 0;
    int matA[MAX_SIZE][MAX_COLS], matB[MAX_SIZE][MAX_COLS], matRes[MAX_SIZE][MAX_COLS];
    int rowsA = 0, colsA = 0, rowsB = 0, colsB = 0; // Initialize to avoid garbage values
    int *dynArr = NULL;
    int choice, index, value, k, n;
    int dynSize = 0; // 2. ADDED: You need a variable to track the current size of dynArr

    while (1) {
        printf("\n--- MASTER MENU ---\n");
        printf("1. Init/Print Array\n2. Insert/Delete\n3. Search (Linear/Binary)\n");
        printf("4. Sort (Bubble/Selection/Insertion/Merge/Quick)\n5. Stats (Max/Min/Sum/Avg)\n");
        printf("6. Reverse/Rotate/MergeTwo\n7. Matrix Ops (Init/Print/Transpose/Add/Mult)\n");
        printf("8. Dynamic Array Ops\n0. Exit\nChoice: ");
        
        if (scanf("%d", &choice) != 1) break; 

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("1. Init  2. Print: ");
                scanf("%d", &n);
                if (n == 1) initArray(arr, &size);
                else printArray(arr, size);
                break;

            case 2:
                printf("1. Insert  2. Delete: ");
                scanf("%d", &n);
                printf("Enter index: ");
                scanf("%d", &index);
                if (n == 1) {
                    printf("Value: "); scanf("%d", &value);
                    insertAt(arr, &size, index, value);
                } else {
                    deleteAt(arr, &size, index);
                }
                break;

            case 3:
                printf("Value to find: ");
                scanf("%d", &value);
                printf("1. Linear  2. Binary: ");
                scanf("%d", &n);
                index = (n == 1) ? linearSearch(arr, size, value) : binarySearch(arr, size, value);
                printf("Found at: %d\n", index);
                break;

            case 4:
                printf("1. Bubble 2. Selection 3. Insertion 4. Merge 5. Quick: ");
                scanf("%d", &n);
                if (n == 1) bubbleSort(arr, size);
                else if (n == 2) selectionSort(arr, size);
                else if (n == 3) insertionSort(arr, size);
                else if (n == 4) mergeSort(arr, 0, size - 1);
                else if (n == 5) quickSort(arr, 0, size - 1);
                printf("Sorted.\n");
                break;

            case 5:
                printf("Max: %d, Min: %d\n", findMax(arr, size), findMin(arr, size));
                printf("Sum: %d, Avg: %.2f\n", sumArray(arr, size), averageArray(arr, size));
                break;

            case 6:
                printf("1. Reverse 2. Rotate 3. MergeTwo: ");
                scanf("%d", &n);
                if (n == 1) reverseArray(arr, size);
                else if (n == 2) {
                    printf("k: "); scanf("%d", &k);
                    rotateLeft(arr, size, k);
                } else {
                    // 3. FIX: You must declare 'out' at the top of the function or in a block { }
                    int b[] = {2, 4, 6};
                    int out[MAX_SIZE * 2]; 
                    mergeSortedArrays(arr, size, b, 3, out);
                    printf("Merged result: ");
                    printArray(out, size + 3);
                }
                break;

            case 7:
                printf("1. Init A  2. Print A  3. Transpose  4. Add (A+B)  5. Mult (Square): ");
                scanf("%d", &n);
                if (n == 1) initMatrix(matA, &rowsA, &colsA);
                else if (n == 2) printMatrix(matA, rowsA, colsA);
                else if (n == 3) transposeMatrix(matA, rowsA, colsA, matRes);
                else if (n == 4) {
                    printf("Init Matrix B:\n");
                    initMatrix(matB, &rowsB, &colsB);
                    addMatrices(matA, matB, matRes, rowsA, colsA);
                } else if (n == 5) {
                    printf("Enter size n for square: "); scanf("%d", &n);
                    multiplyMatrices(matA, matB, matRes, n);
                }
                break;

            case 8:
                printf("1. Create 2. Fill 3. Print 4. Resize 5. Free: ");
                scanf("%d", &n);
                if (n == 1) {
                    printf("Cap: "); scanf("%d", &value);
                    dynArr = createDynamicArray(value);
                } else if (n == 2) {
                    printf("Size to fill: "); scanf("%d", &dynSize);
                    fillArray(dynArr, dynSize);
                } else if (n == 3) {
                    printDynamicArray(dynArr, dynSize);
                } else if (n == 4) {
                    printf("New Cap: "); scanf("%d", &value);
                    dynArr = resizeArray(dynArr, value);
                } else {
                    freeArray(dynArr);
                    dynArr = NULL; // Prevent dangling pointer
                }
                break;

            default:
                printf("Invalid.\n");
        }
    }
}

void string_utils(){
   

#define MAX 1024


    char str[MAX], other[MAX], result[MAX];
    int choice, n, start, len;
    char c;

    printf("Select Function (1-17): ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    // Get primary string for all cases
    printf("Enter string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0; // Remove trailing newline

    switch (choice) {
        case 1: // my_strlen
            printf("Length: %d\n", my_strlen(str));
            break;

        case 2: // my_strcpy
            my_strcpy(result, str);
            printf("Copied string: %s\n", result);
            break;

        case 3: // my_strncpy
            printf("Enter number of chars: ");
            scanf("%d", &n);
            my_strncpy(result, str, n);
            printf("Result: %s\n", result);
            break;

        case 4: // my_strcat
            printf("Enter string to append: ");
            fgets(other, MAX, stdin);
            other[strcspn(other, "\n")] = 0;
            my_strcat(str, other);
            printf("Concatenated: %s\n", str);
            break;

        case 5: // my_strcmp
            printf("Enter string to compare: ");
            fgets(other, MAX, stdin);
            other[strcspn(other, "\n")] = 0;
            printf("Comparison result: %d\n", my_strcmp(str, other));
            break;

        case 6: // my_strncmp
            printf("Enter string to compare and n: ");
            fgets(other, MAX, stdin);
            other[strcspn(other, "\n")] = 0;
            scanf("%d", &n);
            printf("Comparison result: %d\n", my_strncmp(str, other, n));
            break;

        case 7: // toUpperCase
            toUpperCase(str);
            printf("Upper: %s\n", str);
            break;

        case 8: // toLowerCase
            toLowerCase(str);
            printf("Lower: %s\n", str);
            break;

        case 9: // reverseString
            reverseString(str);
            printf("Reversed: %s\n", str);
            break;

        case 10: // countVowels
            printf("Vowels: %d\n", countVowels(str));
            break;

        case 11: // countWords
            printf("Words: %d\n", countWords(str));
            break;

        case 12: // isPalindrome
            if (isPalindrome(str)) printf("It is a palindrome.\n");
            else printf("Not a palindrome.\n");
            break;

        case 13: // removeChar
            printf("Enter char to remove: ");
            scanf(" %c", &c);
            removeChar(str, c);
            printf("Result: %s\n", str);
            break;

        case 14: // removeSpaces
            removeSpaces(str);
            printf("Result: %s\n", str);
            break;

        case 15: // substring
            printf("Enter start index and length: ");
            scanf("%d %d", &start, &len);
            substring(str, start, len, result);
            printf("Substring: %s\n", result);
            break;

        case 16: // compareIgnoreCase
            printf("Enter string to compare: ");
            fgets(other, MAX, stdin);
            other[strcspn(other, "\n")] = 0;
            printf("Result: %d\n", compareIgnoreCase(str, other));
            break;

        default:
            printf("Invalid selection.\n");
    }

    return 0;

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
            case 2: string_utils();break;
        }
    } while (choice != 0);
    return 0;
}

