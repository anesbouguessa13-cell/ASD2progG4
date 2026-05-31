#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} List;

typedef struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
} DLLNode;

typedef struct {
    DLLNode* head;
    DLLNode* tail;
    int size;
} DLL;

void initList(List* L);
int insertBeginning(List* L, int value);
int insertEnd(List* L, int value);
int insertAtPosition(List* L, int pos, int value);
int deleteBeginning(List* L);
int deleteEnd(List* L);
int deleteByValue(List* L, int value);
Node* searchValue(List* L, int value);
void displayList(List* L);
void reverseList(List* L);
void sortListBubble(List* L);
void mergeSortedLists(List* A, List* B, List* result);

void initListDLL(DLL* L);
int insertBeginningDLL(DLL* L, int value);
int insertEndDLL(DLL* L, int value);
int deleteByValueDLL(DLL* L, int value);
void displayForward(DLL* L);
void displayBackward(DLL* L);

#endif