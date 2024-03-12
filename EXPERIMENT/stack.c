#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MIN

typedef struct Stack {
    int height;
    int top;
    int stack[100];
    int capacity;
} Stack;

Stack *_init_Stack() {
    Stack* _init = (Stack *)malloc(sizeof(Stack));
    if (_init == NULL) {
        return NULL;
    }
    _init->height = 0;
    _init->top = -1;
    _init->capacity = 100;

    for (int i = 0; i < _init->capacity; i++) {
        _init->stack[i] = -9999;
    }

    return _init;
}

int isEmpty(Stack *A) {
    return A->top == -1; // return 1 if empty otherwise 0
}

int isFull(Stack *A) {
    return A->top == A->capacity - 1; // return 1 if full otherwise 0
}

void push(Stack *A, int value) {
    if (isFull(A)) {
        printf("Stack is Full (T_T)\n");
        return;
    }
    A->stack[A->top + 1] = value;
    A->top++;
    A->height++;
}

int pop(Stack *A) {
    if (isEmpty(A)) {
        printf("Stack Underflow (~_~)\n");
        return INT_MIN;
    }
    printf("%d has been popped ( ͡° ͜ʖ ͡°) from Stack\n", A->stack[A->top]);
    A->height--;
    return A->stack[A->top--];
}

void clearStack(Stack *A) {
    if (A) 
    {
        free(A);
    }
}

void printStack(Stack *A) {
    if (isEmpty(A)) {
        printf("Stack Underflow (T_T)\n");
        return;
    }

    printf("Stack (from top to bottom):\n");
    for (int i = A->top; i >= 0; i--) {
        printf("%d\n", A->stack[i]);
    }
}