#include "../include/queue.h"

void initQueue(Queue* Q) {
    Q->front = 0;
    Q->rear = 0;
    Q->count = 0;
}

int enqueue(Queue* Q, int value) {
    if (Q->count == MAX_QUEUE_SIZE) return -1;
    Q->data[Q->rear] = value;
    Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
    Q->count++;
    return 0;
}

int dequeue(Queue* Q) {
    if (Q->count == 0) return INT_MIN;
    int dequeuedValue = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
    Q->count--;
    return dequeuedValue;
}

int front(Queue* Q) {
    if (Q->count == 0) return INT_MIN;
    return Q->data[Q->front];
}

int rear(Queue* Q) {
    if (Q->count == 0) return INT_MIN;
    return Q->data[(Q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE];
}