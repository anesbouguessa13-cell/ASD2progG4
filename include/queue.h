#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue* Q);
int enqueue(Queue* Q, int value);
int dequeue(Queue* Q);
int front(Queue* Q);
int rear(Queue* Q);

#endif