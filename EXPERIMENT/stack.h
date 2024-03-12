// Date: 2021/10/10
#ifndef STACK_H
#define STACK_H


typedef struct Stack {
    int height;
    int top;
    int stack[100];
    int capacity;
} Stack;

Stack *_init_Stack();

int isEmpty(Stack *A);

int isFull(Stack *A);

void push(Stack *A, int value);

int pop(Stack *A);

void clearStack(Stack *A);

void printStack(Stack *A);

#endif