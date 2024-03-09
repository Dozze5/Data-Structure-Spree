#include<stdio.h>
#include<stdlib.h>

int size;

typedef struct singlyLinkList{
    int size;
    int data;
    struct singlyLinkList *next;
}Node;


Node *new_Node(int value)
{
    Node *_new = (Node *)malloc(sizeof(Node));
    if(!_new)
    {
        printf("Memory Shortage Erorr in new_Node() (T_T)\n");
        return NULL;
    }
    _new->data = value;
    _new->next = NULL;
    return _new;
}

void shift_at_head(Node **head,int value)
{
    Node *_new = new_Node(value);
    if(!*head)
    {
        *head = _new;
        size++;
        return;
    }

    _new->next = *head;
    *head = _new;
    size++;
    return;
}

void append_at_tail(Node *head,int value)
{
    Node *_new = new_Node(value);
    if(!head)
    {
        printf("Linked List is Empty Inserting At head \n");
        head = _new;
        size++;
        return;
    }

    Node *temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = _new;
    size++;
    return;    

}

void insert_value_by_position(Node **head,int value,int position)
{
    
    if(!*head && position == 1)
    {
        shift_at_head(head,value);
        return;
    }
    if(!*head && position != 1)
    {
        printf("Linked List is Empty and Position is invalid -> %d\n",position);
        return;
    }
    if(size+1 < position)
    {
        printf("Position -> %d is out of bound from Linked List of Size -> %d\n",position,size);
        return ;
    }
    if(position<1)
    {
        printf("Position should start with 1. Invalid Position -> %d\n",position);
        return;
    }
    Node *_new = new_Node(value), *temp = *head;
    int k = 1;

    while(temp->next && k < position-1)
    {
        temp = temp->next;
        k++;
    }



    if(k == position-1)
    {
        _new->next = temp->next;
        temp->next = _new;
        size++;
        return;
    }
    if(position == 1)
    {
        _new->next = *head;
        *head = _new;
        size++;
        return;
    }

}

void delete_from_head(Node **head)
{
    if(!head)
    {
        printf("Linked List is Empty || Size -> %d",size);
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;

    free(temp);
    size--;
    return;
}

void delete_from_tail(Node **head)
{
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d",size);
        return;
    }
    if(!(*head)->next)
    {
        free(*head);
        *head = NULL;
        size--;
        return;
    }
    Node *temp = *head,*prev;

    while (temp->next)      
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    temp = NULL;
    size--;
        
}

void delete_by_position(Node **head, int position)
{
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d",size);
        return;
    }
    if(position == 1)
    {
        delete_from_head(head);
        printf("delete Succes\n");
        return;
    }
    if(position == size)
    {
        delete_from_tail(head);
        printf("delete Succes\n");
        return;
    }
    if(position > size || position < 1)
    {
        printf("Invalid Position size -> %d\n",size);
        return;
    }


    Node *temp = *head, *prev = NULL;
    int k = 1;
    while(k < position)
    {
        prev = temp;
        temp = temp->next;
        k++;
    }
    prev->next = temp->next;
    free(temp);
    temp = NULL;
    size--;
    printf("deletion by position Succes\n");
    return;
}

void display(Node *head)
{
    if(!head)
    {
        printf("link List is Empty Size -> %d\n",size);
        free(head);
        return;
    }
    Node *temp = head;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}
int main()
{   
    Node *head = NULL;
    shift_at_head(&head,5);
    shift_at_head(&head,4);
    // shift_at_head(&head,3);
    shift_at_head(&head,2);
    shift_at_head(&head,1);
    display(head);
    insert_value_by_position(&head,9,1);
    insert_value_by_position(&head,9,7);
    insert_value_by_position(&head,9,3);
    insert_value_by_position(&head,10,9);
    append_at_tail(head,89);
    insert_value_by_position(&head,9,-1);
    insert_value_by_position(&head,20,5);

    display(head);
    // delete_from_head(&head);
    delete_from_tail(&head);
    display(head);
    delete_by_position(&head,6);
    delete_by_position(&head,2);
    delete_by_position(&head,2);
    delete_by_position(&head,2);
    delete_by_position(&head,2);
    delete_by_position(&head,2);
    delete_by_position(&head,1);
    display(head);
    printf("\n%d",size);
    free(head);
    head = NULL;
    return 0;
}