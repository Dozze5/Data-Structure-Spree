#include <stdio.h>
#include <malloc.h>

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
        size++;
    //     // (*tail)->next = NULL;
    // //     printf("%d\n",(*head)->data);
    // // printf("%d\n",(*tail)->data);
        return;
    }

    _new->next = *head;
    (*head)->prev = _new;
    *head = _new;
    size++;
    //     printf("%d\n",(*head)->data);
    // printf("%d\n",(*tail)->data);
    // // printf("%d\n",(*tail)->prev->data);
    return;    
}

void append_at_tail(Node **head, Node **tail, int value)
{   
    // printf("Kya hui 1"); // ! Debuggimg
    Node *_new = new_Node(value);
    if(!*tail)
    {
        printf("Linked List is Empty Inserting At head (~_~) \n");
        *head = _new;
        *tail = *head;
        size++;
        return;
    }
    // printf("Kya hui"); //! Debuggimg

    (*tail)->next = _new;
    _new->prev = *tail;
    *tail  = _new;
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

    while(temp->next && k < position-1)
    {
        temp = temp->next;
        k++;
    }
    if(position == 1)
    {
        shift_at_head(head,tail,value);
        return;
    }
    if(!temp->next)
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
        printf("Linked List is Empty (`_`) Size -> %d\n",size);
        *head = *tail = NULL;
        return;
    }
    Node *temp = *head;

    if(*head == *tail)
    {
        printf("Linked List fully deleted (~_<)\n");
        Node *temp = *head;
        free(temp);
        *head = *tail = NULL;
        size--;
        return;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    size--;
    return;
}

void delete_from_tail(Node **head, Node **tail)
{
    if(!*head)
    {
        printf("Linked List is Empty (`_`) Size -> %d\n",size);
        *head = *tail = NULL;
        return;
    }
    Node *temp = *tail;
    if(*head == *tail)
    {
        printf("Linked List fully deleted (>_~)\n");
        free(temp);
        *head = *tail = NULL;
        size--;
        return;
    }
    *tail = temp->prev;
    (*tail)->next = NULL;
    free(temp);
    size--;
    return;
}

void delete_value_by_position(Node **head, Node **tail,int position)
{
    if(!*head)
    {
        printf("Linked List is Empty || Size -> %d",size);
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
    Node *temp = *head;
    int k = 1;
    while (temp->next && k < position)
    {
        temp = temp->next;
        k++;
    }
    // printf("Idhar tak araha hai kya ?"); //! yes logic problem //? Update it was while() bug used ⁡⁣⁢⁡⁣⁢⁣||⁡⁡ instead of ⁡⁣⁢⁣&&⁡
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
    size--;
    return;    
}

void reverse_linked_list_using_loop(Node **head, Node **tail)
{
    if(!*head)
    {
        printf("Linked List is Empty Size -> %d\n",size);
        return;
    }
    Node *temp = *head, *temp2 = NULL;
    while (temp)
    {
        temp2 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp = temp->prev;
    }
    if(temp2)
    {
        *tail = *head;
        *head = temp2->prev;
    }
    return;
}

void reverse_linked_list_using_recursion(Node **head, Node **tail)
{
    if(!*head)
    {
        printf("Linked List is Empty Size -> %d\n",size);
        return;
    }
    Node *temp = *head;
    if(!temp->next)
    {
        *tail = *head;
        return;
    }
    Node *temp2 = temp->next;
    reverse_linked_list_using_recursion(&temp2,tail);
    temp->next->next = temp;
    temp->next = NULL;
    *head = temp2;
    return;
}
///explaination of the above function the function is called with the head and tail of the linked list
// if the head is null then the linked list is empty and the size is printed and the function is returned
// if the head is not null then the head is assigned to a temp variable and if the next of the temp is null then the tail is assigned to the head and the function is returned
// if the next of the temp is not null then the next of the temp is assigned to a temp2 variable and the function is called with the next of the temp and the tail
// then the next of the next of the temp is assigned to the temp and the next of the temp is assigned to null
// then the head is assigned to the temp2 and the function is returned
// the time complexity of the function is O(n) where n is the number of nodes in the linked list
// the space complexity of the function is O(n) where n is the number of nodes in the linked list
// yep its git copilot generated comments not code


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
    Node *head = NULL, *tail = NULL;
    // shift_at_head(&head,&tail,5);
    // shift_at_head(&head,&tail,4);
    // shift_at_head(&head,&tail,3);
    // shift_at_head(&head,&tail,2);
    // shift_at_head(&head,&tail,1);
    // display(head);
    // // printf("%d\n",head->data);
    // // printf("%d\n",tail->data);
    // // printf("%d\n",tail->prev->data);

    // printf("Kya hua 2"); //! Debugging

    // append_at_tail(&head,&tail,6);

    append_at_tail(&head,&tail,7);
    shift_at_head(&head,&tail,2);
    // append_at_tail(&head,&tail,8);
    // append_at_tail(&head,&tail,9);
    // append_at_tail(&head,&tail,0);
    // // // //     printf("%d\n",head->data);
    // // // // printf("%d\n",tail->data);
    // // // // printf("%d\n",tail->prev->data);

    // insert_value_by_position(&head,&tail,10,1);
    // insert_value_by_position(&head,&tail,20,5);
    // insert_value_by_position(&head,&tail,20,7);
    // insert_value_by_position(&head,&tail,30,2);
    // insert_value_by_position(&head,&tail,30,11);
    // insert_value_by_position(&head,&tail,30,0);

    display(head);

    // delete_from_head(&head,&tail);
    // delete_from_tail(&head,&tail);
    // delete_value_by_position(&head,&tail,3);
    // display(head);
    // delete_value_by_position(&head,&tail,2);
    // display(head);
    // delete_value_by_position(&head,&tail,1);
    // display(head);
    // delete_value_by_position(&head,&tail,2);
    // display(head);
    reverse_linked_list_using_loop(&head,&tail);
    display(head);
    printf("\n%d\n",head->data);
    printf("%d\n",tail->data);
    printf("%d\n",tail->prev->data);
    printf("\n%d\n",size);

    free(head);
    return 0;
}