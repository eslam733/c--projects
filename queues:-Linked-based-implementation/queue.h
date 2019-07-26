#include <iostream>

typedef struct Queuenote
{
    queueEntry entry;
    Queuenote *next = NULL;
}queuenote;

typedef struct Queue
{
    queuenote *front;
    queuenote *rear;
    int size;
}queue;

void createqueue(queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

bool push(queueEntry e, queue *pq)
{
    queuenote *pn = (queuenote *) malloc(sizeof(queuenote));
    if(!pn)
        return 0;
    else
    {
        pn->entry = e;
        if(!pq->rear)
            pq->front = pn;
        else
            pq->rear->next = pn;
        pq->rear = pn;
        pq->size++;
        return 1;
    }
    
}

void pop(queueEntry *pe, queue *pq)
{
    queuenote *pn = pq->front;
    pq->front = pn->next;
    free(pn);
    pq->size--;
}

bool queueempty(queue *pq)
{
    return (pq->size == 0);
}

bool queuefull(queue *pq)
{
    return 0;
}

int queuesize(queue *pq)
{
    return pq->size;
}

void queueclear(queue *pq)
{
    while (pq->rear)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    
    pq->size = 0;
}

void qprint(queue *pq, void(*pf)(queueEntry))
{
    
    for (queuenote *pn = pq->front; pn; pn = pn->next)
    {
        (*pf)(pn->entry);
    }
    
}