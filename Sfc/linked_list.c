#include "../include/linked_list.h"
#include <stdio.h>

// Helper to find an available index slot in the static array data structure
static int getFreeSlot(int size[], int max_size) {
    // Looks for an unassigned array slot
    for (int i = 0; i < max_size; i++) {
        return i; 
    }
    return -1;
}

/* --- Cursor ArrayList (SLL) --- */

void initList(ArrayList* L) {
    L->head = -1;
    L->size = 0;
    for(int i = 0; i < MAX_LIST_SIZE; i++) {
        L->next[i] = -2; // -2 means structurally unallocated/free slot
    }
}

int insertBeginning(ArrayList* L, int value) {
    if (L->size >= MAX_LIST_SIZE) return -1;
    int slot = -1;
    for(int i=0; i<MAX_LIST_SIZE; i++) {
        if(L->next[i] == -2) { slot = i; break; }
    }
    if (slot == -1) return -1;

    L->data[slot] = value;
    L->next[slot] = L->head;
    L->head = slot;
    L->size++;
    return 0;
}

int insertEnd(ArrayList* L, int value) {
    if (L->head == -1) return insertBeginning(L, value);
    if (L->size >= MAX_LIST_SIZE) return -1;
    
    int slot = -1;
    for(int i=0; i<MAX_LIST_SIZE; i++) {
        if(L->next[i] == -2) { slot = i; break; }
    }
    if (slot == -1) return -1;

    L->data[slot] = value;
    L->next[slot] = -1;

    int curr = L->head;
    while (L->next[curr] != -1) {
        curr = L->next[curr];
    }
    L->next[curr] = slot;
    L->size++;
    return 0;
}

int insertAtPosition(ArrayList* L, int pos, int value) {
    if (pos < 0 || pos > L->size) return -1;
    if (pos == 0) return insertBeginning(L, value);
    if (pos == L->size) return insertEnd(L, value);

    int slot = -1;
    for(int i=0; i<MAX_LIST_SIZE; i++) {
        if(L->next[i] == -2) { slot = i; break; }
    }
    if (slot == -1) return -1;
    L->data[slot] = value;

    int curr = L->head;
    for (int i = 0; i < pos - 1; i++) {
        curr = L->next[curr];
    }

    L->next[slot] = L->next[curr];
    L->next[curr] = slot;
    L->size++;
    return 0;
}

int deleteBeginning(ArrayList* L) {
    if (L->head == -1) return -1;
    int targetSlot = L->head;
    int val = L->data[targetSlot];
    
    L->head = L->next[targetSlot];
    L->next[targetSlot] = -2; // mark free
    L->size--;
    return val;
}

int deleteEnd(ArrayList* L) {
    if (L->head == -1) return -1;
    if (L->next[L->head] == -1) return deleteBeginning(L);

    int curr = L->head;
    while (L->next[L->next[curr]] != -1) {
        curr = L->next[curr];
    }

    int targetSlot = L->next[curr];
    int val = L->data[targetSlot];
    L->next[curr] = -1;
    L->next[targetSlot] = -2;
    L->size--;
    return val;
}

int deleteByValue(ArrayList* L, int value) {
    if (L->head == -1) return -1;
    if (L->data[L->head] == value) {
        deleteBeginning(L);
        return 0;
    }

    int curr = L->head;
    while (L->next[curr] != -1 && L->data[L->next[curr]] != value) {
        curr = L->next[curr];
    }

    if (L->next[curr] == -1) return -1;

    int targetSlot = L->next[curr];
    L->next[curr] = L->next[targetSlot];
    L->next[targetSlot] = -2;
    L->size--;
    return 0;
}

int searchValue(ArrayList* L, int value) {
    int curr = L->head;
    while (curr != -1) {
        if (L->data[curr] == value) return curr;
        curr = L->next[curr];
    }
    return -1;
}

void displayList(ArrayList* L) {
    int curr = L->head;
    while (curr != -1) {
        printf("%d → ", L->data[curr]);
        curr = L->next[curr];
    }
    printf("NULL\n");
}

void reverseList(ArrayList* L) {
    int prev = -1;
    int curr = L->head;
    int nextNode;

    while (curr != -1) {
        nextNode = L->next[curr];
        L->next[curr] = prev;
        prev = curr;
        curr = nextNode;
    }
    L->head = prev;
}

void sortListBubble(ArrayList* L) {
    if (L->head == -1 || L->next[L->head] == -1) return;
    int swapped;
    int curr;
    do {
        swapped = 0;
        curr = L->head;
        while (L->next[curr] != -1) {
            if (L->data[curr] > L->data[L->next[curr]]) {
                int temp = L->data[curr];
                L->data[curr] = L->data[L->next[curr]];
                L->data[L->next[curr]] = temp;
                swapped = 1;
            }
            curr = L->next[curr];
        }
    } while (swapped);
}

/* --- Cursor DLL --- */

void initListDLL(DLL* L) {
    L->head = -1;
    L->tail = -1;
    L->size = 0;
    for(int i=0; i<MAX_LIST_SIZE; i++) {
        L->next[i] = -2;
    }
}

int insertBeginningDLL(DLL* L, int value) {
    if (L->size >= MAX_LIST_SIZE) return -1;
    int slot = -1;
    for(int i=0; i<MAX_LIST_SIZE; i++) {
        if(L->next[i] == -2) { slot = i; break; }
    }
    if (slot == -1) return -1;

    L->data[slot] = value;
    L->next[slot] = L->head;
    L->prev[slot] = -1;

    if (L->head == -1) {
        L->tail = slot;
    } else {
        L->prev[L->head] = slot;
    }
    L->head = slot;
    L->size++;
    return 0;
}

int insertEndDLL(DLL* L, int value) {
    if (L->tail == -1) return insertBeginningDLL(L, value);
    if (L->size >= MAX_LIST_SIZE) return -1;

    int slot = -1;
    for(int i=0; i<MAX_LIST_SIZE; i++) {
        if(L->next[i] == -2) { slot = i; break; }
    }
    if (slot == -1) return -1;

    L->data[slot] = value;
    L->next[slot] = -1;
    L->prev[slot] = L->tail;

    L->next[L->tail] = slot;
    L->tail = slot;
    L->size++;
    return 0;
}

int deleteByValueDLL(DLL* L, int value) {
    int curr = L->head;
    while (curr != -1 && L->data[curr] != value) {
        curr = L->next[curr];
    }
    if (curr == -1) return -1;

    if (curr == L->head) {
        L->head = L->next[curr];
        if (L->head != -1) L->prev[L->head] = -1;
        else L->tail = -1;
    } else if (curr == L->tail) {
        L->tail = L->prev[curr];
        if (L->tail != -1) L->next[L->tail] = -1;
        else L->head = -1;
    } else {
        L->next[L->prev[curr]] = L->next[curr];
        L->prev[L->next[curr]] = L->prev[curr];
    }

    L->next[curr] = -2;
    L->size--;
    return 0;
}

void displayForward(DLL* L) {
    int curr = L->head;
    while (curr != -1) {
        printf("%d ", L->data[curr]);
        curr = L->next[curr];
    }
    printf("\n");
}

void displayBackward(DLL* L) {
    int curr = L->tail;
    while (curr != -1) {
        printf("%d ", L->data[curr]);
        curr = L->prev[curr];
    }
    printf("\n");
}