#ifndef QUEUE_H
#define QUEUE_H

#include "../include/common.h"
#include <limits.h>

void initQueue(Queue* Q);
int enqueue(Queue* Q, int value);
int dequeue(Queue* Q);
int front(Queue* Q);
int rear(Queue* Q);

#endif