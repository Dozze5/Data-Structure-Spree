#include <stdio.h>
#include <stdlib.h>

int length;

typedef struct QueueList{
    int value;
    struct QueueList *next;
}Queue;

Queue *_new_Node(int value)
{
    Queue *_new = (Queue *)malloc(sizeof(Queue));

    if(!_new)
    {
        printf("Memory Failuer (T_T)\n");
        exit(101);
    }

    _new->value = value;
    _new->next = NULL;
    return _new;
}

void enqueue(Queue **front, Queue **rear, int value)
{
    Queue *_new = _new_Node(value);
    if(!*front)
    {
        *front = *rear = _new;
        return;
    }
    (*rear)->next = _new;
    (*rear) = _new;
    length++;
}

void dequeue(Queue **front, Queue **rear)
{
    Queue *temp = *front;
    if(!*front)
    {
        printf("Queue is Empty (^_^)\n");
        *front = *rear = NULL;
        return;
    }
    if(*front == *rear)
    {
        free(temp);
        *front = *rear = NULL;
        length--;
        return;
    }

    *front = (*front)->next;
    free(temp);
    length--;
}

void display(Queue *show)
{
    while(show)
    {
        printf("%d ",show->value);
        show = show->next;
    }
    printf("\n");
}


int main()
{   
    //No test Required 
    // I know its Right
    // (^_^) (-_-) (o_o) (T_T)
    return 0;
}