#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MIN

int height = 0;

typedef struct StackNode{
    int value;
    struct StackNode *next;
} Stack;

Stack *_init_Stack() {
    return NULL;
}

Stack *_new_node(int value) {
    Stack *_new = (Stack *)malloc(sizeof(Stack));
    if(_new == NULL) {
        printf("Memory Allocation Failure (T_T)\n");
        return NULL;
    }
    _new->value = value;
    _new->next = NULL;
    return _new;
}

int isEmpty(Stack *top) {
    return !top; // return 1 if empty otherwise 0
}

void push(Stack **top, int value) {
    Stack *_new = _new_node(value);
    if(*top == NULL) {
        *top = _new;
        return;
    }
    _new->next = *top;
    *top = _new;
    height++;
}

int pop(Stack **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow (~_~)\n");
        return INT_MIN;
    }
    Stack *_temp = *top;
    *top = (*top)->next;
    int popped = _temp->value;
    free(_temp);
    height--;
    return popped;
}

void clearStack(Stack **top) {
    Stack *_temp;
    while(*top) {
        _temp = *top;
        *top = (*top)->next;
        free(_temp);
    }
    height = 0;
}

void showStack(Stack *show) {
    if(isEmpty(show)) {
        printf("Stack is Empty (T_T)\n");
        return;
    }
    printf("Stack: \n");
    while(show) {
        printf("%d ", show->value);
        show = show->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Stack *top = _init_Stack();
    int s = (argc > 1) ? argc-1 : 0;

    // push(&top, 10);
    for(int i = s; i>=1; i--) {
        push(&top, atoi(argv[i]));
    }
    
    showStack(top);

    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);

    showStack(top);

    clearStack(&top);
    return 0;
}