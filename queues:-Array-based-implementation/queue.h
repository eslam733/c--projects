#include <iostream>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    queueEntry entry[maxqueue];
}queue;

void createqueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void push(queueEntry e, queue *pq)
{
    pq->rear = (pq->rear + 1) % maxqueue;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void pop(queueEntry *pe, queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % maxqueue;
    pq->size--;
}

bool queueempty(queue *pq)
{
    return (pq->size == 0);
}

bool queuefull(queue *pq)
{
    return (pq->size == maxqueue);
}

int queuesize(queue *pq)
{
    return pq->size;
}

void queueclear(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void qprint(queue *pq, void(*pf)(queueEntry))
{
        int pos = pq->front;
    for (int s = 0; s < (pq->size); s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos+1) % maxqueue;
    }
    
}