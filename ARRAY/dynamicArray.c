#include<stdio.h>
#include<malloc.h>

typedef struct dynamic_Array{
    int size;
    int lastIndex;
    int *array;
}Dynamic_Array;

void init_Dynamic_Array(Dynamic_Array *A, int size)
{
    if(size <= 0)
    {
        printf("Size can't be negative or zero -> %d \n",size);
        return;
    }

    A->size = size;

    A->array = (int *)malloc(A->size * sizeof(int));

    if(!A->array)
    {
        printf("Memory Shortage clear RAM (T_T)\n");
        return;
    }

    for(int i = 0; i < A->size; i++)
    {
        A->array[i] = 0;
    }
    A->lastIndex = -1;
}

void resize_Dyanamic_Array(Dynamic_Array *A, int extra_Size)
{
    if(extra_Size <= 0)
    {
        printf("Extra Size can't be zero or negative (T_T)\n");
        return;
    }
    if(!A->array)
    {
        printf("A->array kharab hai (^_^)\n");
        return;
    }
    int new_size = A->size+extra_Size;
    int *ptr = (int *)malloc(new_size * sizeof(int));

    if(!ptr)
    {
        printf("Memory Shortage clear RAM (T_T)\n");
        return;
    }

    for(int i = 0; i < A->size; i++)
    {
        ptr[i] = A->array[i];
    }
    free(A->array);
    A->array = ptr;
    A->size = new_size;

    printf("Resize Succes\n");
}

void insert_element_in_Dyanamic_Array(Dynamic_Array *A, int element, int position)
{
    if(position-1 > A->lastIndex+1 || position <= 0)
    {
        printf("\nPosition Invalid\n");
    }
    else if(A->lastIndex == A->size-1)
    {
        
        printf("\nDyanamic Array is full\n");
        printf("Do you wnat to increase the size of array (^_<)\npress -> 1 to resize() or any key to exit()\n");
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        {   
            printf("\nEnter extra size -> ");
            int ex;
            scanf("%d",&ex);
            resize_Dyanamic_Array(A,ex);
            int i;
            for(i = A->lastIndex; i >= position-1 ;i--)
            {
                A->array[i+1] =  A->array[i];
            }
            A->array[position-1] = element;
            A->lastIndex++;
            printf("Resize and Insert Succes (^_^)\n");
        }
    }
    else
    {   
        int i;
        for(i = A->lastIndex; i >= position-1 ;i--)
        {
            A->array[i+1] =  A->array[i];
        }
        A->array[position-1] = element;
        A->lastIndex++;
        printf("Succes\n");
    }
}

void append_in_Dynamic_Array(Dynamic_Array *A, int element)
{
    if(A->lastIndex == A->size-1)
    {        
            resize_Dyanamic_Array(A,1);
            
            A->array[A->lastIndex+1] = element;
            A->lastIndex++;
            printf("Resize and append Succes (^_^)\n");
        
    }
    else
    {
        A->array[A->lastIndex+1] = element;
        A->lastIndex++;
        printf("Succes_append\n");
    }
}

void delete_element_from_Dynamic_Array(Dynamic_Array *A, int position)
{
    if(position<=0 || position-1 > A->lastIndex)
    {
        printf("Invalid Index\n");
    }
    else
    {
        for(int i = position-1; i < A->lastIndex ;i++)
        {
            A->array[i] = A->array[i+1];
        }
        printf("Succes_delete\n");
        A->lastIndex--;
    }
}

void delete_Dyanamic_Array(Dynamic_Array *A)
{
    if(!A->array)
    {
        printf("Already Deleted(>_<)\n");
        return;
    }
    A->size = 0;
    A->lastIndex-1;
    free(A->array);
    A->array = NULL;
}

void display(Dynamic_Array *A)
{
    printf("\nSize of Dynamic Array -> %d\n",A->size);
    for(int i = 0; i < A->lastIndex+1; i++)
    {
        printf("%d ",A->array[i]);
    }
    printf("\nLast Index of Array -> %d\n",A->lastIndex);
}


int main(int argc, char *argv[])
{   
    Dynamic_Array A;
    init_Dynamic_Array(&A,5);
    // insert_element_in_Dyanamic_Array(&A,1,1);
    // insert_element_in_Dyanamic_Array(&A,1,1);
    // insert_element_in_Dyanamic_Array(&A,1,1);
    // insert_element_in_Dyanamic_Array(&A,1,1);
    // insert_element_in_Dyanamic_Array(&A,1,1);
    // insert_element_in_Dyanamic_Array(&A,1,1);   
    insert_element_in_Dyanamic_Array(&A,1,1);
    insert_element_in_Dyanamic_Array(&A,2,2);
    insert_element_in_Dyanamic_Array(&A,3,3);
    insert_element_in_Dyanamic_Array(&A,4,4);
    insert_element_in_Dyanamic_Array(&A,5,5);   
    // insert_element_in_Dyanamic_Array(&A,5,7);   
    // insert_element_in_Dyanamic_Array(&A,5,-1);   
    append_in_Dynamic_Array(&A,90);
    // delete_Dyanamic_Array(&A);
    display(&A);
    delete_element_from_Dynamic_Array(&A,4);
    display(&A);
    delete_element_from_Dynamic_Array(&A,1);
    display(&A);
    delete_element_from_Dynamic_Array(&A,4);
    display(&A);
    delete_element_from_Dynamic_Array(&A,1);
    display(&A);
    delete_element_from_Dynamic_Array(&A,1);
    display(&A);
    delete_element_from_Dynamic_Array(&A,1);
    display(&A);
    delete_element_from_Dynamic_Array(&A,1);
    display(&A);
    // free(A->array);
    return 0;
}
