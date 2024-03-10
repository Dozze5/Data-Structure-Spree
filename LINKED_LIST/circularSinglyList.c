#include <stdio.h>
#include <stdlib.h>

int size;

typedef struct Node{
    int data;
    struct Node *next;
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

void shift_at_head(Node **head, Node **tail, int value)
{
    Node *_new = new_Node(value);

    if(!*head)
    {
        *head = _new;
        *tail = _new;
        (*tail)->next = *head;
        size++;
        return;
    }

    _new->next = *head;
    *head = _new;
    (*tail)->next = *head;
    size++;
    return;
}

void append_from_tail(Node **head, Node **tail, int value)
{
    Node *_new = new_Node(value);

    if(!(*head))
    {
        *head = _new;
        *tail = _new;
        (*tail)->next = *head;
        size++;
        return;
    }
    _new->next = (*tail)->next;
    (*tail)->next = _new;
    *tail = _new;
    size++;
    return;
}

void insert_value_by_position(Node **head, Node **tail, int value, int position)
{
    if(!*head && position == 1)
    {
        shift_at_head(head,tail,value);
        return;
    }
    if(!*head && position != 1)
    {
        printf("Linked List is Empty and Position is invalid -> %d\n",position);
        return;
    }
    if(size+1 < position || position < 1)
    {
        printf("Position -> %d is out of bound from Linked List of Size -> %d\n",position,size);
        return ;
    }

    int k = 1;
    Node *temp = *head;
    Node *_new = new_Node(value);
    while(k < position-1)
    {
        temp = temp->next;
        k++;
    }

    if(position==1)
    {
        shift_at_head(head,tail,value);
        return;
    }

    if(temp == *tail)
    {
        append_from_tail(head,tail,value);
        return;
    }
    
    _new->next = temp->next;
    temp->next = _new;
    size++;
    return;

}

void delete_from_head(Node **head,Node **tail)
{
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d",size);
        return;
    }
    if(*head == *tail)
    {
        Node *temp = *head;
        free(temp);
        *head = *tail = NULL;
        size--;
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    (*tail)->next = *head;

    free(temp);
    size--;
    return;
}

void delete_from_tail(Node **head, Node **tail)
{
    Node *temp = *head;
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d",size);
        *head = *tail = NULL;
        return;
    }
    if(*head == *tail)
    {
        free(temp);
        *head = *tail = NULL;
        size--;
        return;
    }

    while(temp->next != *tail)
    {
        temp = temp->next;
    }

    free(*tail);
    *tail = temp;
    (*tail)->next = *head;
    size--;
}

void delete_by_position(Node **head, Node **tail, int position)
{
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d",size);
        *head = *tail = NULL;
        return;
    }
    if(position == 1)
    {
        delete_from_head(head,tail);
        printf("delete Succes\n");
        return;
    }
    if(position == size)
    {
        delete_from_tail(head,tail);
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

void reverse__circular_Linked_list_using_loop(Node **head,Node **tail)
{
    if(!head)
    {
        printf("link List is Empty Size -> %d\n",size);
        free(*head);
        return;
    }
    if((*head)->next == NULL)
    {
        return;
    }

    Node *prev = NULL, *curr = *head, *forward = curr->next;

    while(forward != *head)
    {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = forward->next;
    }

    curr->next = prev;
    *head = curr;
    *tail = forward;
    (*tail)->next = *head;
    // // forward->next = curr;
    // // (*tail)->next = NULL;
    //// teu
    // // *tail = forward;
    // // return;
    // printf("%d  %d  %d \n",(*tail)->data,(*tail)->next->data,(*head)->data);
    
}

void reverse__circular_Linked_list_using_recursion(Node *curr, Node *prev, Node **head, Node **tail)
{
    if(!*head)
    {
        printf("link List is Empty || Size -> %d\n",size);
        return;
    }
    if(curr == *tail)
    {
        curr->next = prev;
        *tail = *head;
        *head = curr;
        (*tail)->next = *head;
        return;
    }

    Node *_next = curr->next;
    curr->next = prev;
    reverse__circular_Linked_list_using_recursion(_next,curr,head,tail);

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
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while (temp != head);
    printf("\n");
    
}

int main()
{
    Node *head = NULL, *tail = NULL;
    // insert_value_by_position(&head,&tail,9,1);
    // insert_value_by_position(&head,&tail,10,1);
    // insert_value_by_position(&head,&tail,0,2);
    // display(head);
    // // delete_from_head(&head,&tail);
    // delete_from_tail(&head,&tail);
    // display(head);
    // // printf("%d\n",tail->data);
    // // printf("%d\n",head->data);
    // // printf("%d\n",tail->next->data);
    shift_at_head(&head,&tail,5);
    shift_at_head(&head,&tail,4);
    shift_at_head(&head,&tail,3);
    shift_at_head(&head,&tail,2);
    shift_at_head(&head,&tail,1);
    display(head);
    reverse__circular_Linked_list_using_loop(&head,&tail);
    display(head);
    reverse__circular_Linked_list_using_recursion(head,NULL,&head,&tail);
    display(head);
    // delete_by_position(&head,&tail,2);
    // display(head);
    // delete_by_position(&head,&tail,4);
    // display(head);
    // delete_by_position(&head,&tail,1);
    // display(head);
    // delete_by_position(&head,&tail,2);
    // display(head);
    // delete_by_position(&head,&tail,1);
    // display(head);
    // insert_value_by_position(&head,&tail,21,1);
    // display(head);
    // insert_value_by_position(&head,&tail,22,2);
    // display(head);
    // insert_value_by_position(&head,&tail,23,7);
    // insert_value_by_position(&head,&tail,24,3);
    // display(head);
    // insert_value_by_position(&head,&tail,25,9);
    // display(head);
    // // // append_at_tail(head,&tail,89);
    // // // insert_value_by_position(&head,&tail,9,-1);
    // insert_value_by_position(&head,&tail,20,5);
    // display(head);

    // delete_from_tail(&head,&tail);
    // display(head);
    // delete_from_tail(&head,&tail);
    // display(head);
    if(head){
        printf("\n%d",tail->data);
        printf("\n%d",head->data);
        printf("\n%d",tail->next->data);
    }
    return 0;
}