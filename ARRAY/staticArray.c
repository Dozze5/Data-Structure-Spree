#include <stdio.h>

struct Array
{   
    int lastIndex;
    int size;
    int array[100];
};

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

void Insert_element_in_Array(struct Array *A, int element, int position)
{
    if(position-1 > A->lastIndex+1 || position <= 0)
    {
        printf("\nPosition Invalid\n");
    }
    else if(A->lastIndex == A->size-1)
    {
        printf("\nOverflow\n");
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

void append_in_Array(struct Array *A, int element)
{
    if(A->lastIndex == A->size-1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        A->array[A->lastIndex+1] = element;
        A->lastIndex++;
        printf("Succes_append\n");
    }
    
}

void display(struct Array *A)
{
    for(int i = 0; i < A->lastIndex+1; i++)
    {
        printf("%d ",A->array[i]);
    }
    printf("\n%d\n",A->lastIndex);
}

void delete_element_from_Array(struct Array *A, int position)
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
        printf("Succec_delete\n");
        A->lastIndex--;
    }
    
}

int main()
{
    int n;
    struct Array A;

    printf("Enter Size of Array -> ");
    scanf("%d",&n);

    init_Array(&A , n);

    Insert_element_in_Array(&A,1,1);
    display(&A);
    Insert_element_in_Array(&A,2,2);
    Insert_element_in_Array(&A,3,3);
    Insert_element_in_Array(&A,4,2);
    Insert_element_in_Array(&A,5,1);
    Insert_element_in_Array(&A,5,5);
    Insert_element_in_Array(&A,10,7);
    Insert_element_in_Array(&A,10,9);
    append_in_Array(&A,20);
    append_in_Array(&A,30);
    append_in_Array(&A,40);
    append_in_Array(&A,50);
    display(&A);
    delete_element_from_Array(&A,11);
    display(&A);
    delete_element_from_Array(&A,1);
    display(&A);
    delete_element_from_Array(&A,6);
    display(&A);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    delete_element_from_Array(&A,1);
    display(&A);
    delete_element_from_Array(&A,1);
    display(&A);


    return 0;
}

