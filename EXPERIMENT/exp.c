#include <stdio.h>
#include "stack.h"

int main()
{
    Stack *A = _init_Stack();
    push(A,20);
    push(A,30);
    push(A,40);
    printStack(A);
    pop(A);

    return 0;
}