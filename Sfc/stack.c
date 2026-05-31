#include "../include/stack.h"

void initStack(Stack* S) {
    S->top = -1;
}

int push(Stack* S, int value) {
    if (isFull(S)) return -1;
    S->top++;
    S->data[S->top] = value;
    return 0;
}

int pop(Stack* S) {
    if (isEmpty(S)) return INT_MIN;
    int poppedValue = S->data[S->top];
    S->top--;
    return poppedValue;
}

int peek(Stack* S) {
    if (isEmpty(S)) return INT_MIN;
    return S->data[S->top];
}

int isEmpty(Stack* S) {
    return S->top == -1;
}

int isFull(Stack* S) {
    return S->top == MAX_STACK_SIZE - 1;
}