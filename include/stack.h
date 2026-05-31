#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* S);
int push(Stack* S, int value);
int pop(Stack* S);
int peek(Stack* S);
int isEmpty(Stack* S);
int isFull(Stack* S);

#endif