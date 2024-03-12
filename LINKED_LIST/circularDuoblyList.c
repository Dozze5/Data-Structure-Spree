#include<stdio.h>
#include<malloc.h>

int size;

typedef struct DoublyLinkedList{
    struct DoublyLinkedList *prev;
    int data;
    struct DoublyLinkedList *next;;
}Node;


Node *new_Node(int value)
{
    Node *_new = (Node *)malloc(sizeof(Node));
    if(!_new)
    {
        printf("Memory Shortage Erorr in new_Node() (T_T)\n");
        free(_new);
        return NULL;
    }
    _new->prev = NULL;
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
        *tail = *head;
        (*tail)->next = *head;
        (*head)->prev = *tail;
        size++;
        return;
    }

    _new->next = *head;
    (*head)->prev = _new;
    *head = _new;
    (*tail)->next = *head;
    (*head)->prev = *tail;
    size++;
    return;    
}

void append_at_tail(Node **head, Node **tail, int value)
{   
    
    Node *_new = new_Node(value);
    if(!*tail)
    {
        printf("Linked List is Empty Inserting At head (~_~) \n");
        *head = _new;
        *tail = *head;
        (*tail)->next = *head;
        (*head)->prev = *tail;
        size++;
        return;
    }


    (*tail)->next = _new;
    _new->prev = *tail;
    *tail  = _new;
    (*tail)->next = *head;
    (*head)->prev = *tail;
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

    Node *_new = new_Node(value), *temp = *head;
    int k = 1;

    while(k < position-1)
    {
        temp = temp->next;
        k++;
    }
    if(position == 1)
    {
        shift_at_head(head,tail,value);
        return;
    }

    if(temp == *tail)
    {
        append_at_tail(head,tail,value);
        return;
    }
    _new->next = temp->next;
    temp->next->prev = _new;
    _new->prev = temp;
    temp->next = _new;
    size++;
    return;

}

void delete_from_head(Node **head,Node **tail)
{
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d\n",size);
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
    (*head)->prev = *tail;

    free(temp);
    size--;
    return;
}

void delete_from_tail(Node **head, Node **tail)
{
    Node *temp = *head;
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d\n",size);
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
    *tail = NULL;
    *tail = temp;
    (*tail)->next = *head;
    (*head)->prev = *tail;
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
    if(position > size || position < 1)
    {
        printf("Invalid Position size -> %d\n",size);
        return;
    }
    if(position == size)
    {
        delete_from_tail(head,tail);
        printf("delete Succes\n");
        return;
    }


    Node *temp = *head;
    int k = 1;
    while(k < position)
    {
        temp = temp->next;
        k++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
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
    if(*head == *tail)
    {
        printf("Seriously (-_-)\n");
        return;
    }

    Node *previos = *tail, *curr = *head;

    do
    {
        curr->prev = curr->next;
        curr->next = previos;
        previos = curr;
        curr = curr->prev;
    }while(curr != *head);


    if(previos == *tail)
    {
        *tail = curr;
        *head = previos;
    }
    // // forward->next = curr;
    // // (*tail)->next = NULL;
    //// teu
    // // *tail = forward;
    // // return;
    // printf("%d  %d  %d \n",(*tail)->data,(*tail)->next->data,(*head)->data);
    
}


void display(Node *head)
{
    if(!head)
    {
        printf("link List is Empty Size -> %d\n",size);
        return;
    }
    Node *temp = head;
    do
    {

        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
    
}
// void reverse_linked_list_using_recursion(Node **head, Node **tail)
// {
//     if(!*head)
//     {
//         printf("link List is Empty Size -> %d\n",size);
//         free(*head);
//         return;
//     }
//     if(*head == *tail)
//     {
//         printf("Seriously (-_-)\n");
//         return;
//     }
//     Node *temp = *head;
//     *head = *tail;
//     *tail = temp;
//     reverse_linked_list_using_recursion(&(*head)->next,tail);
//     return;
// }

int main()
{
    Node *head, *tail;
    head = tail = NULL;


    // shift_at_head(&head,&tail,10);
    // shift_at_head(&head,&tail,20);
    // shift_at_head(&head,&tail,30);

    // append_at_tail(&head,&tail,100);
    // append_at_tail(&head,&tail,200);
    // append_at_tail(&head,&tail,300);

    insert_value_by_position(&head,&tail,1000,1);
    insert_value_by_position(&head,&tail,3000,2);
    insert_value_by_position(&head,&tail,2000,2);
    // insert_value_by_position(&head,&tail,4000,4);
    // insert_value_by_position(&head,&tail,10000,3);
    // insert_value_by_position(&head,&tail,6000,6);  expexted error
    display(head);

    // delete_from_head(&head,&tail);
    // delete_from_head(&head,&tail);
    // delete_from_head(&head,&tail);
    // delete_from_head(&head,&tail);
    // delete_from_head(&head,&tail);

    //! tail delete 
    // delete_from_tail(&head,&tail);
    // delete_from_tail(&head,&tail);
    // delete_from_tail(&head,&tail);
    // delete_from_tail(&head,&tail);
    // delete_from_tail(&head,&tail);
    // delete_from_tail(&head,&tail);

    //! By Position Delete
    // delete_by_position(&head,&tail,3);
    // display(head);
    // delete_by_position(&head,&tail,3);
    // display(head);
    // delete_by_position(&head,&tail,3);
    // display(head);
    // delete_by_position(&head,&tail,1);
    // display(head);
    // delete_by_position(&head,&tail,1);
    // display(head);

    // reverse__circular_Linked_list_using_loop(&head,&tail);
    reverse_linked_list_using_recursion(&head,&tail);
    display(head);
    if(head)
    {
        printf("head->prev->data == %d\nhead->next->data == %d\nhead->data == %d\n",head->prev->data,head->next->data,head->data);
        printf("tail->prev->data == %d\ntail->next->data == %d\ntail->data == %d\n",tail->prev->data,tail->next->data,tail->data);
    }
    return 0;
}