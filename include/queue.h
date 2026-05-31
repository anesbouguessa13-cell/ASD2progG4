#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "common.h" // Include your common types here!

// SLL Cursor-Based Prototypes
void initList(ArrayList* L);
int insertBeginning(ArrayList* L, int value);
int insertEnd(ArrayList* L, int value);
int insertAtPosition(ArrayList* L, int pos, int value);
int deleteBeginning(ArrayList* L);
int deleteEnd(ArrayList* L);
int deleteByValue(ArrayList* L, int value);
int searchValue(ArrayList* L, int value); // Returns index instead of Node*
void displayList(ArrayList* L);
void reverseList(ArrayList* L);
void sortListBubble(ArrayList* L);
void mergeSortedLists(ArrayList* A, ArrayList* B, ArrayList* result);

// DLL Cursor-Based Prototypes
void initListDLL(DLL* L);
int insertBeginningDLL(DLL* L, int value);
int insertEndDLL(DLL* L, int value);
int deleteByValueDLL(DLL* L, int value);
void displayForward(DLL* L);
void displayBackward(DLL* L);

#endif