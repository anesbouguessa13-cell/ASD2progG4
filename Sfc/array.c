#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialize: set size to 0 — array is logically empty */
void initArray(int arr[], int* size) {
    *size = 0;
}

/* Print in [a, b, c] format */
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/* Insert value at index — shift elements right first */
int insertAt(int arr[], int* size, int index, int value) {
    if (index < 0 || index > *size) return -1;  // invalid index
    if (*size >= MAX_1D) return -1;             // array full

    for (int i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
    return 0;
}
int   deleteAt(int arr[], int* size, int index){
    
    
    if (index < 0 || index >= *size) {
        return -1;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    return 0; 
}

    

int   linearSearch(int arr[], int size, int value){
    
}
int   binarySearch(int arr[], int size, int value){}
void  bubbleSort(int arr[], int size){}
void  selectionSort(int arr[], int size){}
void  insertionSort(int arr[], int size){}
void  mergeSort(int arr[], int left, int right){}
void  quickSort(int arr[], int low, int high){}
int   findMax(int arr[], int size){}
int   findMin(int arr[], int size){}
int   sumArray(int arr[], int size){}
double averageArray(int arr[], int size){}
void  reverseArray(int arr[], int size){}
void  rotateLeft(int arr[], int size, int k){}
void  mergeSortedArrays(int a[], int na, int b[], int nb, int out[]){}

/* --- 2D Matrix --- */
void  initMatrix(int m[][MAX_COLS], int* rows, int* cols){}
void  printMatrix(int m[][MAX_COLS], int rows, int cols){}
void  transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]){}
void  addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols){}
void  multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n){}

/* --- Dynamic Array --- */
int*  createDynamicArray(int capacity){}
void  fillArray(int* arr, int size){}
void  printDynamicArray(int* arr, int size){}
int*  resizeArray(int* arr, int newCapacity){}
void  freeArray(int* arr){}

