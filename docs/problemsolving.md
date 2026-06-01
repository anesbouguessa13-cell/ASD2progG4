
---

# Data Structures and Utilities Library: Comprehensive Function Documentation

---

## 📂 Part A — 1D Static Arrays

This module works with fixed-size arrays where the logical size is passed via a pointer (`int* size`). This allows modifications to the size variable to persist across function frames.

### `initArray`

* **Signature:** `void initArray(int arr[], int* size)`
* **Explanation:** Sets the memory tracking loop size to zero (`*size = 0`). It leaves the elements of the array untouched (they remain garbage values), as setting the size to 0 logically empties the array.
* **Edge Cases:** Must always be called before any other array operations to prevent reading garbage memory sizes.

### `printArray`

* **Signature:** `void printArray(int arr[], int size)`
* **Explanation:** Loops through the active array up to `size - 1` and prints the numbers wrapped in a structured format: `[a, b, c]`.
* **Edge Cases:** If `size == 0`, it immediately short-circuits and prints `[]` to handle empty collections cleanly.

### `insertAt`

* **Signature:** `int insertAt(int arr[], int* size, int index, int value)`
* **Explanation:** Adds an element at a specific index. To make space, it runs a downward loop from `*size` down to `index`, shifting elements one slot to the right: `arr[i] = arr[i - 1]`. Then, it places the new value into `arr[index]` and increments `*size`.
* **Edge Cases:** Returns `-1` if the array is already at max capacity (`*size >= MAX_1D`) or if the index is invalid (`index < 0 || index > *size`).

### `deleteAt`

* **Signature:** `int deleteAt(int arr[], int* size, int index)`
* **Explanation:** Removes an element from a specific index. It runs an upward loop from `index` up to `*size - 2`, shifting elements one position to the left: `arr[i] = arr[i + 1]`. This safely overwrites the target value, and then decrements `*size`.
* **Edge Cases:** Returns `-1` if the array is empty or if the index is out of bounds (`index < 0 || index >= *size`).

### `linearSearch`

* **Signature:** `int linearSearch(int arr[], int size, int value)`
* **Explanation:** Scans sequential memory starting from index `0` up to `size - 1`. It checks if `arr[i] == value` and returns the index of the first match.
* **Edge Cases:** Returns `-1` if the value isn't found or if the array is completely empty.

### `binarySearch`

* **Signature:** `int binarySearch(int arr[], int size, int value)`
* **Explanation:** Calculates a midpoint index `mid = low + (high - low) / 2`. If `arr[mid]` matches the target, it returns the index. If the target is smaller, it narrows the search to the left half (`high = mid - 1`); if larger, it shifts to the right half (`low = mid + 1`).
* **Edge Cases:** Requires the array to be **pre-sorted**. Returns `-1` if pointers cross (`low > high`), meaning the item is missing.

### `bubbleSort`

* **Signature:** `void bubbleSort(int arr[], int size)`
* **Explanation:** Runs adjacent comparisons (`arr[j] > arr[j + 1]`) and swaps values out of order. Each full pass pushes the largest unsorted value to the end. An early-exit flag tracks if any swaps occurred; if a full pass runs without a swap, the array is sorted and it breaks early.

### `selectionSort`

* **Signature:** `void selectionSort(int arr[], int size)`
* **Explanation:** Divides the array into sorted and unsorted sections. It loops through the unsorted section to find the absolute minimum value's index, then performs a single swap to place it at the front of that section. It makes exactly $n-1$ swaps.

### `insertionSort`

* **Signature:** `void insertionSort(int arr[], int size)`
* **Explanation:** Iterates from index 1 to `size - 1`. It takes the current element (key) and shifts previous elements one position to the right as long as they are greater than the key, creating a gap to insert the key into its correct sorted position.

### `mergeSort`

* **Signature:** `void mergeSort(int arr[], int left, int right)`
* **Explanation:** A divide-and-conquer algorithm that recursively splits the array in half until individual elements are isolated (`left >= right`). It then uses a helper function, `merge()`, to combine these pieces back together in sorted order into a temporary buffer.

### `quickSort`

* **Signature:** `void quickSort(int arr[], int low, int high)`
* **Explanation:** Selects a pivot element (often the last item). It rearranges the array so that everything smaller than the pivot shifts to its left, and everything larger shifts to its right. It then recursively applies the same logic to both sub-arrays.

### `findMax` / `findMin`

* **Signature:** `int findMax(int arr[], int size)`
* **Explanation:** Initializes an execution tracking variable to `arr[0]`. It scans from index 1 through `size - 1`, updating the tracking variable whenever a larger (or smaller for `findMin`) element is found.

### `sumArray`

* **Signature:** `int sumArray(int arr[], int size)`
* **Explanation:** Initializes an accumulator variable to 0. It iterates through the array, adding each element's value to the running total.
* **Edge Cases:** Safely returns `0` if the array contains zero entries (`size == 0`).

### `averageArray`

* **Signature:** `double averageArray(int arr[], int size)`
* **Explanation:** Calls `sumArray` to get the total sum of the array, then divides it by the size. To avoid integer truncation, it explicitly casts the sum to a double before dividing.
* **Edge Cases:** If `size == 0`, it immediately returns `0.0` to avoid a crash caused by dividing by zero.

### `reverseArray`

* **Signature:** `void reverseArray(int arr[], int size)`
* **Explanation:** Uses a two-pointer swapping strategy that loops from index `0` up to the midpoint ($\lfloor \text{size} / 2 \rfloor$). It swaps elements at opposite ends of the array (`arr[i]` and `arr[size - 1 - i]`) in place.

### `rotateLeft`

* **Signature:** `void rotateLeft(int arr[], int size, int k)`
* **Explanation:** Shifts all array values left by $k$ positions. To optimize performance, it uses a three-step reversal technique: first, reverse the first $k$ elements; next, reverse the remaining elements; finally, reverse the entire array.
* **Edge Cases:** Uses `k = k % size` to correctly handle instances where the number of rotations is larger than the array itself.

### `mergeSortedArrays`

* **Signature:** `void mergeSortedArrays(int a[], int na, int b[], int nb, int out[])`
* **Explanation:** Uses two separate tracking pointers to read from sorted input arrays `a` and `b` simultaneously. It compares the values at both pointers, copies the smaller value into the `out` array, and advances that pointer. Once one array is exhausted, it copies over any remaining elements from the other array.

---

## 🔲 Part B — 2D Static Matrices

This module manages two-dimensional structures using fixed column sizes (`MAX_COLS`) to ensure proper contiguous memory access.

### `initMatrix`

* **Signature:** `void initMatrix(int m[][MAX_COLS], int* rows, int* cols)`
* **Explanation:** Prompts the user to enter the matrix dimensions, validating that they fall within `MAX_ROWS` and `MAX_COLS`. It then runs nested loops to populate every cell in the grid via `scanf`.

### `printMatrix`

* **Signature:** `void printMatrix(int m[][MAX_COLS], int rows, int cols)`
* **Explanation:** Iterates through the matrix using nested row and column loops. It prints each element with a fixed field width (e.g., `%4d`) to keep columns aligned, adding a newline character (`\n`) at the end of each row.

### `transposeMatrix`

* **Signature:** `void transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS])`
* **Explanation:** Flips a matrix over its diagonal by mapping rows to columns. It copies elements from the source matrix to the output matrix using the formula `out[j][i] = m[i][j]`, which swaps the final dimension layout.

### `addMatrices`

* **Signature:** `void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols)`
* **Explanation:** Performs element-wise matrix addition using nested loops. It adds corresponding elements from matrices `a` and `b` and stores the result in matrix `r`: `r[i][j] = a[i][j] + b[i][j]`.

### `multiplyMatrices`

* **Signature:** `void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n)`
* **Explanation:** Multiplies two $n \times n$ square matrices using a standard three-loop algorithm. After initializing the result cell `r[i][j]` to 0, a third loop calculates the dot product of row `i` from matrix `a` and column `j` from matrix `b`.

### `sumDiagonal` / `sumAntiDiagonal`

* **Signature:** `int sumDiagonal(int m[][MAX_COLS], int n)`
* **Explanation:** Extracts diagonal values from square matrices in a single loop pass. `sumDiagonal` targets cells where row and column indices match (`m[i][i]`), while `sumAntiDiagonal` targets cells along the opposite diagonal line (`m[i][n - 1 - i]`).

### `isSymmetric`

* **Signature:** `int isSymmetric(int m[][MAX_COLS], int n)`
* **Explanation:** Checks if a matrix is equal to its transpose ($M = M^T$). It optimizes this check by only comparing cells above the main diagonal line (`j > i`) against their corresponding counterparts below it (`m[i][j] == m[j][i]`). It returns `1` if symmetrical, and `0` if any mismatch is found.

### `sortRows`

* **Signature:** `void sortRows(int m[][MAX_COLS], int rows, int cols)`
* **Explanation:** Iterates through the matrix row by row. It treats each row as an independent 1D array of length `cols` and applies a sorting algorithm (like bubble sort or insertion sort) to organize its elements.

---

## 💎 Part C — Dynamic Arrays

This module manages memory allocations directly on the system heap using `malloc`, `realloc`, and `free`.

### `createDynamicArray`

* **Signature:** `int* createDynamicArray(int capacity)`
* **Explanation:** Allocates a contiguous block of memory on the heap using `malloc(capacity * sizeof(int))`.
* **Edge Cases:** Explicitly verifies if the returned pointer is `NULL` before returning it, preventing crashes from allocation failures.

### `fillArray`

* **Signature:** `void fillArray(int* arr, int size)`
* **Explanation:** Iterates through an allocated dynamic array from index `0` up to `size - 1`, reading user inputs via `scanf` directly into each slot (`&arr[i]`).

### `resizeArray`

* **Signature:** `int* resizeArray(int* arr, int newCapacity)`
* **Explanation:** Resizes an existing heap allocation using `realloc`. To avoid memory leaks, it stores the result in a temporary pointer first. If `realloc` returns `NULL`, the original memory remains intact; if successful, it returns the updated address.

### `freeArray`

* **Signature:** `void freeArray(int* arr)`
* **Explanation:** Releases the allocated heap memory back to the system by calling `free(arr)`.
* **Edge Cases:** To prevent dangling pointer bugs, the pointer variable in the calling function should be set to `NULL` immediately after this function runs.

---

## 🔗 Singly Linked List (SLL)

A dynamic data structure where each node contains a value and a pointer to the next node in the sequence.

### `initList`

* **Signature:** `void initList(List* L)`
* **Explanation:** Initializes an empty list by setting the head pointer `L->head` to `NULL` and the size counter `L->size` to 0.

### `insertBeginning`

* **Signature:** `int insertBeginning(List* L, int value)`
* **Explanation:** Allocates a new node on the heap. It assigns the input value to the node's data field, points its `next` pointer to the current head node (`newNode->next = L->head`), and updates the list head to point to this new node.

### `insertEnd`

* **Signature:** `int insertEnd(List* L, int value)`
* **Explanation:** Allocates a new node and sets its `next` pointer to `NULL`. If the list is empty, it reuses `insertBeginning`. Otherwise, it traverses to the end of the list until `current->next == NULL` and links the new node there.

### `insertAtPosition`

* **Signature:** `int insertAtPosition(List* L, int pos, int value)`
* **Explanation:** Traverses the list to find the node right before the target position (`pos - 1`). It links the new node's `next` pointer to this node's successor, then updates the node at `pos - 1` to point to the new node.

### `deleteBeginning`

* **Signature:** `int deleteBeginning(List* L)`
* **Explanation:** Removes the first item from the list. It creates a temporary pointer to hold the current head node, advances `L->head` to the next node in line (`L->head->next`), extracts the data, and frees the old node.

### `deleteEnd`

* **Signature:** `int deleteEnd(List* L)`
* **Explanation:** Removes the last item from the list. It traverses the list using two pointers to keep track of the current node and the node right before it. Once it reaches the last node, it unlinks it by setting the second-to-last node's `next` pointer to `NULL`, then frees the final node.

### `deleteByValue`

* **Signature:** `int deleteByValue(List* L, int value)`
* **Explanation:** Searches the list for a specific value. If the matching node is the head, it handles it like `deleteBeginning`. Otherwise, it tracks the preceding node, changes its `next` pointer to skip over the matching node, and frees the removed node.

### `searchValue`

* **Signature:** `Node* searchValue(List* L, int value)`
* **Explanation:** Iterates sequentially through the list starting from the head node. If it finds a node where `node->data == value`, it returns a pointer to that node. If it reaches the end (`NULL`) without a match, it returns `NULL`.

### `displayList`

* **Signature:** `void displayList(List* L)`
* **Explanation:** Traverses the list from the head node to the end, printing each node's value followed by an arrow symbol to show the list structure clearly: `10 -> 20 -> 30 -> NULL`.

### `reverseList`

* **Signature:** `void reverseList(List* L)`
* **Explanation:** Reverses the list in place without allocating new nodes. It uses three pointers (`prev`, `current`, and `next`) to flip each node's pointer direction as it iterates through the list, finally updating `L->head` to point to the new front node.

### `sortListBubble`

* **Signature:** `void sortListBubble(List* L)`
* **Explanation:** Sorts the list using a bubble sort algorithm. Instead of rearranging the nodes themselves, it iterates through the list and swaps the `data` values inside the nodes whenever they are out of order.

### `mergeSortedLists`

* **Signature:** `void mergeSortedLists(List* A, List* B, List* result)`
* **Explanation:** Combines two sorted lists into a single sorted result list. It uses two pointers to compare the front nodes of lists `A` and `b`, appending the smaller value to the result list until both input lists are fully processed.

---

## ⛓️ Doubly Linked List (DLL)

A list structure where each node contains pointers to both its successor (`next`) and its predecessor (`prev`), allowing bidirectional traversal.

### `initListDLL`

* **Signature:** `void initListDLL(DLL* L)`
* **Explanation:** Sets both the `head` and `tail` tracking pointers to `NULL` and resets the size counter to 0.

### `insertBeginningDLL`

* **Signature:** `int insertBeginningDLL(DLL* L, int value)`
* **Explanation:** Allocates a new node. It sets the node's `next` pointer to the current head and its `prev` pointer to `NULL`. If the list is already populated, it updates the old head's `prev` pointer to point back to the new node; if the list is empty, this new node also becomes the tail.

### `insertEndDLL`

* **Signature:** `int insertEndDLL(DLL* L, int value)`
* **Explanation:** Allocates a new node and hooks its `prev` link to the current tail node. If the list contains elements, the old tail's forward `next` pointer is linked to this new node, and the list's tail pointer is updated to point to it.

### `deleteByValueDLL`

* **Signature:** `int deleteByValueDLL(DLL* L, int value)`
* **Explanation:** Finds the target node and updates its neighboring nodes to point directly to each other, bypassing the target node completely: `node->prev->next = node->next` and `node->next->prev = node->prev`. This allows for clean removal without manual list traversal.

### `displayForward` / `displayBackward`

* **Signature:** `void displayForward(DLL* L)`
* **Explanation:** `displayForward` starts at the head and follows the `next` pointers to print the list from front to back. `displayBackward` starts at the tail and follows the `prev` pointers to print the list in reverse order.

---

## 🥞 Stack (Array-Based)

A Last-In, First-Out (LIFO) structure where elements are added and removed from the same end, tracked by a `top` index.

### `initStack`

* **Signature:** `void initStack(Stack* S)`
* **Explanation:** Sets `S->top = -1`. This initializes the stack as empty, as a negative index indicates there are no valid elements stored yet.

### `push`

* **Signature:** `int push(Stack* S, int value)`
* **Explanation:** Adds an item to the top of the stack. It increments the `top` index tracking pointer (`++top`) and writes the new value into that slot in the data array.
* **Edge Cases:** Returns `-1` if the stack is already full (`S->top == MAX_STACK_SIZE - 1`), preventing a stack overflow error.

### `pop`

* **Signature:** `int pop(Stack* S)`
* **Explanation:** Removes and returns the top item from the stack. It retrieves the value stored at `data[top]`, then decrements the `top` index pointer.
* **Edge Cases:** Returns a sentinel value like `INT_MIN` if the stack is empty (`S->top == -1`), preventing a stack underflow error.

### `peek`

* **Signature:** `int peek(Stack* S)`
* **Explanation:** Inspects the top item of the stack by returning the value at `data[top]`. Unlike `pop`, it does not decrement the `top` index, leaving the stack unchanged.

### `isEmpty` / `isFull`

* **Signature:** `int isEmpty(Stack* S)`
* **Explanation:** Simple utility checks. `isEmpty` returns true if `S->top == -1`. `isFull` returns true if `S->top == MAX_STACK_SIZE - 1`.

---

## 🎟️ Queue (Circular Array-Based)

A First-In, First-Out (FIFO) structure that uses modulo arithmetic to wrap index pointers back around to the start of the array, preventing out-of-bounds errors.

### `initQueue`

* **Signature:** `void initQueue(Queue* Q)`
* **Explanation:** Initializes the queue by setting the `front`, `rear`, and `count` trackers all to 0, resetting the circular buffer.

### `enqueue`

* **Signature:** `int enqueue(Queue* Q, int value)`
* **Explanation:** Adds an item to the back of the queue. It stores the value at the `rear` index, then advances the pointer using circular wrapping arithmetic: `Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE`. It then increments the `count` tracker.
* **Edge Cases:** Returns `-1` if the queue is full (`Q->count == MAX_QUEUE_SIZE`).

### `dequeue`

* **Signature:** `int dequeue(Queue* Q)`
* **Explanation:** Removes and returns the front item from the queue. It grabs the value stored at the `front` index, then advances the pointer using circular wrapping arithmetic: `Q->front = (Q->front + 1) % MAX_QUEUE_SIZE`. It then decrements the `count` tracker.
* **Edge Cases:** Returns `INT_MIN` if the queue is completely empty (`Q->count == 0`).

### `front` / `rear`

* **Signature:** `int front(Queue* Q)`
* **Explanation:** Peer functions that look at values without removing them. `front()` returns the item at the `front` index. `rear()` returns the last successfully added item, located at `(Q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE`.

---

## 💾 Part F — File Utilities (Binary I/O)

This module handles persistent data storage by reading and writing structural configurations directly to disk as raw bytes.

### `createBinaryFile`

* **Signature:** `int createBinaryFile(const char* filename)`
* **Explanation:** Opens a file in write-binary mode (`"wb"`). This action creates a fresh, empty file on disk (or clears an existing one). The file is closed immediately to save changes. Returns `-1` if the operation fails.

### `writeRecord`

* **Signature:** `int writeRecord(const char* filename, Record* r)`
* **Explanation:** Opens the specified file in append-binary mode (`"ab"`). It appends a `Record` struct directly to the end of the file using `fwrite`, then closes the file.

### `readRecord`

* **Signature:** `int readRecord(const char* filename, int index, Record* r)`
* **Explanation:** Opens a file in read-binary mode (`"rb"`). It uses `fseek` to jump directly to the byte offset of the target record using the formula `index * sizeof(Record)`. It then reads that block of data directly into a memory reference pointer using `fread`.

### `countRecords`

* **Signature:** `int countRecords(const char* filename)`
* **Explanation:** Opens a file in `"rb"` mode and uses `fseek(fp, 0, SEEK_END)` to jump to the very end of the file. It then calls `ftell(fp)` to get the total size of the file in bytes. Dividing this number by `sizeof(Record)` gives the total number of records stored.

### `appendRecord`

* **Signature:** `int appendRecord(const char* filename, Record* r)`
* **Explanation:** Reuses the core logic of `writeRecord`. By opening the file in `"ab"` mode, the file pointer automatically moves to the end of the file, safely appending the new data without overwriting existing records.

### `searchRecordById`

* **Signature:** `int searchRecordById(const char* filename, int id, Record* result)`
* **Explanation:** Opens a file in `"rb"` mode and reads records sequentially using a loop. It checks each record's ID field against the target ID; if a match is found, it copies the data into the `result` pointer and returns the loop index.

### `updateRecord`

* **Signature:** `int updateRecord(const char* filename, int index, Record* newData)`
* **Explanation:** Opens a file in read/write binary mode (`"r+b"`), which allows modifying file contents without clearing the file first. It uses `fseek` to jump directly to the target record's position, then overwrites it with the new data using `fwrite`.

### `copyBinaryFile`

* **Signature:** `int copyBinaryFile(const char* src, const char* dest)`
* **Explanation:** Backs up or duplicates data by opening a source file in `"rb"` mode and a destination file in `"wb"` mode. It loops through the source file, reading records one by one and writing them directly into the destination file.

---

## 🔤 Part G — String Utilities

> ⚠️ **Strict Implementation Constraint:** These functions are built completely from scratch using character-by-character loops. No functions from the standard `<string.h>` library are used.

### `my_strlen`

* **Signature:** `int my_strlen(const char* s)`
* **Explanation:** Iterates through a string character by character using a loop that increments a counter until it hits the null terminator character (`'\0'`). It then returns the final count.

### `my_strcpy`

* **Signature:** `char* my_strcpy(char* dest, const char* src)`
* **Explanation:** Copies a string by looping through the source string and assigning each character to the destination string (`dest[i] = src[i]`). The loop continues until it copies the null terminator character (`'\0'`).

### `my_strncpy`

* **Signature:** `char* my_strncpy(char* dest, const char* src, int n)`
* **Explanation:** A safer version of string copy that copies at most `n` characters from the source string. If the source string is shorter than `n`, it pads the remaining positions in the destination buffer with null terminators (`'\0'`).

### `my_strcat`

* **Signature:** `char* my_strcat(char* dest, const char* src)`
* **Explanation:** Appends a string by first finding the end of the destination string (the `'\0'` character). It then copies the source string character by character into the destination buffer starting from that position, ensuring the combined string is properly null-terminated.

### `my_strcmp`

* **Signature:** `int my_strcmp(const char* a, const char* b)`
* **Explanation:** Compares two strings character by character. If it encounters a mismatch, it returns the difference between their character values (`a[i] - b[i]`). If both strings match exactly, it reaches the end and returns `0`.

### `my_strncmp`

* **Signature:** `int my_strncmp(const char* a, const char* b, int n)`
* **Explanation:** Compares two strings character by character just like `my_strcmp`, but stops after checking `n` characters. This is useful for comparing prefixes or partial strings.

### `toUpperCase` / `toLowerCase`

* **Signature:** `void toUpperCase(char* s)`
* **Explanation:** Iterates through a string character by character. `toUpperCase` checks for lowercase letters (`'a'` to `'z'`) and subtracts 32 from their ASCII values to convert them to uppercase. `toLowerCase` checks for uppercase letters (`'A'` to `'Z'`) and adds 32 to convert them to lowercase.

### `reverseString`

* **Signature:** `void reverseString(char* s)`
* **Explanation:** Reverses a string in place using a two-pointer approach. One pointer starts at index 0 and the other starts at the last character (`length - 1`). The pointers swap characters and move inward toward each other until they meet in the middle.

### `countVowels` / `countConsonants`

* **Signature:** `int countVowels(const char* s)`
* **Explanation:** Loops through a string character by character. It converts each letter to lowercase and checks if it matches a vowel (`a`, `e`, `i`, `o`, `u`). For consonants, it verifies that the character is an alphabetic letter but not a vowel.

### `countWords`

* **Signature:** `int countWords(const char* s)`
* **Explanation:** Counts words by tracking state changes. It uses a flag variable (`inWord`) to detect transitions from whitespace (spaces, tabs, newlines) to non-whitespace characters, incrementing the word counter each time a new word starts.

### `isPalindrome`

* **Signature:** `int isPalindrome(const char* s)`
* **Explanation:** Checks if a string reads the same backward as forward. Using two pointers at opposite ends of the string, it moves inward and compares characters. If any mismatch is found, it returns `0`; if the pointers cross without a mismatch, it returns `1`.

### `removeChar`

* **Signature:** `void removeChar(char* s, char c)`
* **Explanation:** Removes a specific character from a string in a single pass using a two-pointer shifting technique. A read pointer inspects every character, but the write pointer only saves characters that do not match the target character `c`, effectively filtering it out.

### `removeSpaces`

* **Signature:** `void removeSpaces(char* s)`
* **Explanation:** Uses the same two-pointer shifting technique as `removeChar`, but filters out spaces (`' '`) and tab characters (`'\t'`) to strip all whitespace from the string in place.

### `substring`

* **Signature:** `void substring(const char* src, int start, int len, char* dest)`
* **Explanation:** Extracts a portion of a string. It copies `len` characters from the source string starting at the `start` index into the `dest` buffer, then automatically appends a null terminator (`'\0'`) to complete the substring.

### `compareIgnoreCase`

* **Signature:** `int compareIgnoreCase(const char* a, const char* b)`
* **Explanation:** Compares two strings character by character like `my_strcmp`, but converts uppercase letters to lowercase on the fly before comparing them. This allows it to check for equality while ignoring case differences.

---

## 📈 Part H — Dataset Analysis Application

This application acts as an analytics engine, combining your file management routines, struct data sorting, calculations, and reporting pipelines into an integrated system.

### `loadDataset`

* **Signature:** `int loadDataset(const char* filename, Record arr[], int* count)`
* **Explanation:** Opens a binary data file in read mode. It runs a loop that reads `Record` structs directly into an array allocation buffer up to the maximum limit (`MAX_1D`), then updates the total count variable.

### `displayDataset`

* **Signature:** `void displayDataset(Record arr[], int count)`
* **Explanation:** Loops through the loaded records and prints them out in a clean, aligned tabular layout. It uses explicit column width formatting codes (like `%-25s` and `%-12.2f`) to ensure data columns line up correctly.

### `sortDatasetByField`

* **Signature:** `void sortDatasetByField(Record arr[], int count, char* field)`
* **Explanation:** A dynamic sorting function. It uses `strcmp` to check the `field` parameter string (matching `"id"`, `"name"`, or `"score"`), then runs a sorting algorithm that compares the selected struct field to organize the records.

### `findMaxByField` / `findMinByField`

* **Signature:** `Record findMaxByField(Record arr[], int count)`
* **Explanation:** Scans through the records array in a single pass, tracking the record with the absolute highest (or lowest) score field. Once the loop finishes, it returns the entire matching `Record` struct.

### `averageByField`

* **Signature:** `float averageByField(Record arr[], int count)`
* **Explanation:** Iterates through the records array to calculate the total sum of all the score fields combined. It then divides this sum by the total record count and returns the result as a float. Returns `0.0f` if the array is empty.

### `filterByCondition`

* **Signature:** `int filterByCondition(Record arr[], int count, float threshold, Record out[])`
* **Explanation:** Filters data by iterating through the input array and checking each record against a condition. Records with a score higher than the `threshold` value are copied into the `out` output array. It returns the total number of records that matched the condition.

### `saveBinaryReport`

* **Signature:** `int saveBinaryReport(const char* filename, Record arr[], int count)`
* **Explanation:** Exports data by opening a target file in write-binary mode (`"wb"`). It uses `fwrite` in a loop to save the filtered or sorted records array straight to disk as a clean binary report file.