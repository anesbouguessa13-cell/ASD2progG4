#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "common.h"

// Cursor-based Singly Linked List (ArrayList)
void initList(ArrayList* L);
int insertBeginning(ArrayList* L, int value);
int insertEnd(ArrayList* L, int value);
int insertAtPosition(ArrayList* L, int pos, int value);
int deleteBeginning(ArrayList* L);
int deleteEnd(ArrayList* L);
int deleteByValue(ArrayList* L, int value);
int searchValue(ArrayList* L, int value); // Returns array index instead of a pointer
void displayList(ArrayList* L);
void reverseList(ArrayList* L);
void sortListBubble(ArrayList* L);

// Cursor-based Doubly Linked List (DLL)
void initListDLL(DLL* L);
int insertBeginningDLL(DLL* L, int value);
int insertEndDLL(DLL* L, int value);
int deleteByValueDLL(DLL* L, int value);
void displayForward(DLL* L);
void displayBackward(DLL* L);

#endif