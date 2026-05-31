#include "../include/linked_list.h"

/* --- Singly Linked List Implementation --- */

void initList(List* L) {
    L->head = NULL;
    L->size = 0;
}

int insertBeginning(List* L, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    
    newNode->data = value;
    newNode->next = L->head;
    L->head = newNode;
    L->size++;
    return 0;
}

int insertEnd(List* L, int value) {
    if (L->head == NULL) {
        return insertBeginning(L, value);
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    
    newNode->data = value;
    newNode->next = NULL;
    
    Node* temp = L->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    L->size++;
    return 0;
}

int insertAtPosition(List* L, int pos, int value) {
    if (pos < 0 || pos > L->size) return -1;
    if (pos == 0) return insertBeginning(L, value);
    if (pos == L->size) return insertEnd(L, value);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->data = value;
    
    Node* temp = L->head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    L->size++;
    return 0;
}

int deleteBeginning(List* L) {
    if (L->head == NULL) return -1;
    
    Node* temp = L->head;
    int deletedValue = temp->data;
    L->head = L->head->next;
    free(temp);
    L->size--;
    return deletedValue;
}

int deleteEnd(List* L) {
    if (L->head == NULL) return -1;
    
    if (L->head->next == NULL) {
        Node* temp = L->head;
        int deletedValue = temp->data;
        L->head = NULL;
        free(temp);
        L->size--;
        return deletedValue;
    }
    
    Node* temp = L->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    Node* toDelete = temp->next;
    int deletedValue = toDelete->data;
    temp->next = NULL;
    free(toDelete);
    L->size--;
    return deletedValue;
}

int deleteByValue(List* L, int value) {
    if (L->head == NULL) return -1;
    
    if (L->head->data == value) {
        Node* temp = L->head;
        L->head = L->head->next;
        free(temp);
        L->size--;
        return 0;
    }
    
    Node* current = L->head;
    Node* prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) return -1;
    
    prev->next = current->next;
    free(current);
    L->size--;
    return 0;
}

Node* searchValue(List* L, int value) {
    Node* temp = L->head;
    while (temp != NULL) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayList(List* L) {
    Node* temp = L->head;
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(List* L) {
    Node* prev = NULL;
    Node* current = L->head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L->head = prev;
}

void sortListBubble(List* L) {
    if (L->head == NULL || L->head->next == NULL) return;
    
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = L->head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void mergeSortedLists(List* A, List* B, List* result) {
    initList(result);
    Node* currA = A->head;
    Node* currB = B->head;
    
    while (currA != NULL && currB != NULL) {
        if (currA->data <= currB->data) {
            insertEnd(result, currA->data);
            currA = currA->next;
        } else {
            insertEnd(result, currB->data);
            currB = currB->next;
        }
    }
    
    while (currA != NULL) {
        insertEnd(result, currA->data);
        currA = currA->next;
    }
    
    while (currB != NULL) {
        insertEnd(result, currB->data);
        currB = currB->next;
    }
}

/* --- Doubly Linked List Implementation --- */

void initListDLL(DLL* L) {
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

int insertBeginningDLL(DLL* L, int value) {
    DLLNode* newNode = (DLLNode*)malloc(sizeof(DLLNode));
    if (newNode == NULL) return -1;
    
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = L->head;
    
    if (L->head == NULL) {
        L->tail = newNode;
    } else {
        L->head->prev = newNode;
    }
    
    L->head = newNode;
    L->size++;
    return 0;
}

int insertEndDLL(DLL* L, int value) {
    if (L->tail == NULL) {
        return insertBeginningDLL(L, value);
    }
    
    DLLNode* newNode = (DLLNode*)malloc(sizeof(DLLNode));
    if (newNode == NULL) return -1;
    
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = L->tail;
    
    L->tail->next = newNode;
    L->tail = newNode;
    L->size++;
    return 0;
}

int deleteByValueDLL(DLL* L, int value) {
    DLLNode* temp = L->head;
    
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    
    if (temp == NULL) return -1;
    
    if (temp == L->head) {
        L->head = temp->next;
        if (L->head != NULL) {
            L->head->prev = NULL;
        } else {
            L->tail = NULL;
        }
    } else if (temp == L->tail) {
        L->tail = temp->prev;
        if (L->tail != NULL) {
            L->tail->next = NULL;
        } else {
            L->head = NULL;
        }
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    L->size--;
    return 0;
}

void displayForward(DLL* L) {
    DLLNode* temp = L->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(DLL* L) {
    DLLNode* temp = L->tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}