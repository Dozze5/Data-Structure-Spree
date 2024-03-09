# Array Implementation in C

This C code demonstrates a simple implementation of a array using a structure. The array is initialized with a specified size and provides functionalities for inserting, appending, deleting elements, and displaying the array.

## Code

```c
#include <stdio.h>

struct Array
{   
    int lastIndex;
    int size;
    int array[100];
};
```
## Defining the Array Struct
We define a struct called Array to represent an array. The struct has two fields:

- `lastIndex`: an integer that stores the index of the last element in the array.
- `size`: an integer that stores the size of the array.
- `array`: an array of integers with a fixed size of 100.

```c
void init_Array(struct Array *A, int size)
{
    if(size >= 100)
    {
        printf("\nArray has only 100 blocks\n");

    }

    A->size = size;
    A->lastIndex = -1;

    for(int i = 0; i < A->size; i++)
    {
        A->array[i] = 0;
    }
}
```

gcc staticArray.c -o staticArray