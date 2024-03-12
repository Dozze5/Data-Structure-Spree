#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MIN

typedef struct DynamicStack {
    int height;
    int top;
    int *stack;
    int capacity;
} Stack;

Stack *_init_Stack() {
    Stack* _init = (Stack *)malloc(sizeof(Stack));
    
    if (_init == NULL) {
        printf("Memory Allocation Failure (T_T)\n");
        return NULL;
    }
    _init->height = 0;
    _init->top = -1;
    _init->capacity = 10;

    _init->stack = (int *)malloc(_init->capacity * sizeof(int)); // Allocate memory for the stack array

    if (_init->stack == NULL) {
        printf("Memory Allocation Failure (T_T)\n");
        free(_init); // Free previously allocated memory for Stack structure
        return NULL;
    }

    for (int i = 0; i < _init->capacity; i++) {
        _init->stack[i] = -9999;
    }

    return _init;
}


int isEmpty(Stack *A) {
    return A->top == -1; // return 1 if empty otherwise 0
}

int isFull(Stack *A) {
    return A->top+1 == A->capacity; // return 1 if full otherwise 0
}

void _resize_Stack(Stack *A) {
    int o = A->capacity;
    A->capacity *= 2;
    A->stack = realloc(A->stack, A->capacity*sizeof(int));
    if(A->stack == NULL) {
        printf("Resize Failure (T_T)\n");
        A->capacity = o;
        return;
    }
}

void push(Stack *A, int value) {
    if (isFull(A)) {
        _resize_Stack(A);
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

int main() {
    Stack *A = _init_Stack();
    push(A, 10);
    push(A, 20);
    push(A, 30);
    push(A, 40);
    push(A, 50);
    push(A, 60);
    push(A, 70);
    push(A, 80);
    push(A, 90);
    push(A, 100);
    push(A, 110);
    push(A, 120);
    printStack(A);

    pop(A);
    pop(A);
    printStack(A);

    pop(A);

    printf("%d\n",isEmpty(A));
    printf("%d\n",isFull(A));
    printf("%d\n",A->top);
    printf("%d\n",A->height);

    // Free memory allocated for the stack
    clearStack(A);

    return 0;
}