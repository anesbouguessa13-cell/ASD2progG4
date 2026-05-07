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

    

int linearSearch(int arr[], int size, int value){
  
    for (int i = 0; i < size; i++) { 
        if (arr[i] == value) {
            return i; 
        }
        
    }
    
    return -1; 
}


int   binarySearch(int arr[], int size, int value){
    
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] < value) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }
    return -1;
}



void  bubbleSort(int arr[], int size){
    
    int i, j, temp;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0; 

    
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; 
            }
        }

        
        if (swapped == 0) {
            break;
        }
    }


}
void  selectionSort(int arr[], int size){
   
    int i, j, minIndex, temp;

    
    for (i = 0; i < size - 1; i++) {
        
        minIndex = i;

        
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}


void  insertionSort(int arr[], int size){
    
    int i, key, j;
    
    
    for (i = 1; i < size; i++) {
        key = arr[i]; 
        j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        
        arr[j + 1] = key;
    }
}


void  mergeSort(int arr[], int left, int right){
      int i, j, k,mid;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  
    i = 0; 
    j = 0;
    k = left; 
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void  quickSort(int arr[], int low, int high){
    
   
    int pivot = arr[high]; 
    int i = (low - 1);    

    for (int j = low; j < high; j++) {
        
        if (arr[j] <= pivot) {
            i++; 
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

     
}


int   findMax(int arr[], int size){
    
    int maxVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return maxVal;
}


int findMin(int arr[], int size) {
    
    int minVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    return minVal;
}


int   sumArray(int arr[], int size){
    
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    return total;

}
double averageArray(int arr[], int size){
    
    if (size <= 0) {
        return 0.0;
    }

    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    return (double)total / size;

}
void  reverseArray(int arr[], int size){
    
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

}


void rotateLeft(int arr[], int size, int k) {
    if (size <= 0) return;
    
    k = k % size;
    if (k == 0) return;

    
}

void  mergeSortedArrays(int a[], int na, int b[], int nb, int out[]){
    
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            out[k] = a[i];
            i++;
        } else {
            out[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < na) {
        out[k] = a[i];
        i++;
        k++;
    }

    while (j < nb) {
        out[k] = b[j];
        j++;
        k++;
    }

}

/* --- 2D Matrix --- */
void  initMatrix(int m[][MAX_COLS], int* rows, int* cols){
   


    int r, c;

    printf("Enter rows and columns (max %d each): ", MAX_ROWS);
    scanf("%d %d", &r, &c);

    if (r > MAX_ROWS) r = MAX_ROWS;
    if (c > MAX_COLS) c = MAX_COLS;
    if (r < 0) r = 0;
    if (c < 0) c = 0;

    *rows = r;
    *cols = c;

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

}
void  printMatrix(int m[][MAX_COLS], int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}
void  transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out[j][i] = m[i][j];
        }
    }
}
void  addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}
void  multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = 0;
            for (int k = 0; k < n; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

/* --- Dynamic Array --- */
int*  createDynamicArray(int capacity){
    int* arr = (int*)malloc(capacity * sizeof(int));
    
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    
    return arr;
}
void  fillArray(int* arr, int size){
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int*  resizeArray(int* arr, int newCapacity){
    
    int* temp = (int*)realloc(arr, newCapacity * sizeof(int));

    if (temp == NULL) {
        printf("Error: Memory reallocation failed.\n");
        return NULL;
    }

    return temp;
}
void  freeArray(int* arr){
    free(arr);
    arr = NULL;
}

