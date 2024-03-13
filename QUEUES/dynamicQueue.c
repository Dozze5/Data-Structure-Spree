#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int front;
    int rear;
    int *queue;
    int length;
    int capacity;
}Queue;

Queue *_init_Queue()
{
    Queue *_new = (Queue *)malloc(sizeof(Queue));

    if(!_new)
    {
        printf("Memory Failure (T_T)\n");
        exit(400);
    }
    _new->front = -1;
    _new->rear = -1;
    _new->length = 0;
    _new->capacity = 10;
    _new->queue = (int *)malloc(_new->capacity * sizeof(int));

    if(!_new->queue)
    {
        printf("Memory Failure (T_T)\n");
        exit(400);
    }    
    for(int i = 0; i < _new->capacity; i++)
    _new->queue[i] = -9999;

    return _new;
}

bool isEmpty(Queue *Q)
{
    return Q->front == -1;
}

bool isFull(Queue *Q)
{
    return (Q->rear+1)%Q->capacity == Q->front;
}

void _resize(Queue *Q)
{
    int o = Q->capacity;
    Q->capacity *= 2;
    Q->queue = realloc(Q->queue, Q->capacity*sizeof(int));

    if(Q->queue == NULL) {
        printf("Resize Failure (T_T)\n");
        Q->capacity = o;
        return;
    }
    if(Q->rear<Q->front)
    {
        for(int i = 0; i < Q->front; i++)
        {
            Q->queue[i+o] = Q->queue[i]; 
        }
        Q->rear = Q->rear+o;
    }

}

void enQueue(Queue *Q, int value)
{
    if(isFull(Q))
    {
        _resize(Q);
    }
    if(isEmpty(Q)) {
        Q->front = 0;
        Q->rear = 0;
    }
    else {
        Q->rear = (Q->rear+1)%Q->capacity;
    }
    Q->queue[Q->rear] = value;
    Q->length++;
}

int deQueue(Queue *Q)
{
    if(isEmpty(Q))
    {
        Q->front = -1;
        Q->rear = -1;
        printf("(\"_\")\n");
        return -9999;
    }

    int dQ = Q->queue[Q->front];

    if(Q->front == Q->rear)
    {
        Q->front = -1;
        Q->rear = -1;
        Q->length = 0;
    }
    else
    {
        Q->front = (Q->front +1)%Q->capacity;
        Q->length--;
    }
    return dQ;
}

void display(Queue *show)
{
    int i = show->front;
    if(isEmpty(show))
    {
        printf("Queue is Empty\n");
        return;
    }
    do{
        printf("%d ",show->queue[i]);
        i = (i+1)%show->capacity;
    }while(i != (show->rear + 1) % show->capacity);
    printf("\n");
}

void destroyQueue(Queue* queue) {
    free(queue);
}

int main()
{   
    Queue *Q = _init_Queue();

    enQueue(Q,10);
    enQueue(Q,20);
    enQueue(Q,30);
    enQueue(Q,40);
    enQueue(Q,50);
    enQueue(Q,60);
    enQueue(Q,70);
    enQueue(Q,80);
    enQueue(Q,90);
    enQueue(Q,100);
    enQueue(Q,100);
    display(Q);

        
    printf("index -> %d || queue[front] -> %d\n",Q->front, Q->queue[Q->front]);
    printf("index -> %d || queue[rear] -> %d\n",Q->rear, Q->queue[Q->rear]);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);

    display(Q);
        
    printf("index -> %d || queue[front] -> %d\n",Q->front, Q->queue[Q->front]);
    printf("index -> %d || queue[rear] -> %d\n",Q->rear, Q->queue[Q->rear]);

    enQueue(Q,110);
    enQueue(Q,120);
    enQueue(Q,130);
    enQueue(Q,90);
    display(Q);
    printf("index -> %d || queue[front] -> %d\n",Q->front, Q->queue[Q->front]);
    printf("index -> %d || queue[rear] -> %d\n",Q->rear, Q->queue[Q->rear]);
    
    destroyQueue(Q);


    return 0;
}