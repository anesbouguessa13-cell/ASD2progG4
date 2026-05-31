#ifndef STACK_H
#define STACK_H

#include "common.h"
#include <limits.h>

void initStack(Stack* S);
int push(Stack* S, int value);
int pop(Stack* S);
int peek(Stack* S);
int isEmpty(Stack* S);
int isFull(Stack* S);

#endif