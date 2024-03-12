# Singly Linked List

### A Single linked list, in its simplest form, is a collection of nodes that collectively form a linear sequence. Each node stores a reference to an object that is an element of the sequence, as well as a reference to the next node of the list.


## Structure of Node 
```c    
    typedef struct singlyLinkList{
        int size;
        int data;
        struct singlyLinkList *next;
    }Node;
```
<img src="images/download.png" alt="" width="30%" height="40%">

## Operations on Singly Linked List
### 1. `Insertion`
Adding a new node to a linked list involves adjusting the pointers of the existing nodes to maintain the proper sequence. Insertion can be performed at the beginning, end, or any position within the list

   ### Insertion at the beginning
**Approach:**

To insert a node at the start/beginning/front of a Linked List, follow these steps:

- Create a new node with the given data.
- Set the `next` pointer of the new node to point to the current head of the Linked List.
- Update the head pointer to point to the new node.

Here is the code implementation in C:
```c
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
```
### Insertion at the end
**Approach:**
To insert a node at the end of a Linked List, follow these steps:
- Create a new node with the given data.
- Traverse the list to find the last node.
- Set the `next` pointer of the last node to point to the new node.

Here is the code implementation in C:
```c
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
```
### Insertion at the given position

**The insert_at_position function inserts a new node with the given value at the specified position in the linked list.**

1. `Empty List and Position Check`: The function first checks if the linked list is empty (head is NULL) and if the position is 1. If both conditions are true, the new node is inserted as the head node using the shift_at_head function.

2. `Invalid Position Check`: If the linked list is empty but the position is not 1, the function prints an error message indicating that the position is invalid and returns.

3. `Out of Bounds Check`: The function checks if the position is out of bounds of the linked list by comparing it with size + 1 (where size is the number of nodes in the linked list). If the position is greater, an error message is printed and the function returns.

4. `Negative Position Check`: If the position is less than 1, the function prints an error message indicating that the position is invalid and returns.

5. `Node Insertion`: If none of the above conditions are met, a new node is created and a temporary pointer is used to traverse the linked list until the desired position is reached. The new node is then inserted at the correct position by updating the next pointers of the relevant nodes.
6. `Size Update`: After the new node is inserted, the size variable is incremented to reflect the addition of the new node.

Here is the code implementation in C:
```c

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
```

### 2. `Deletion`
Deletion in a singly linked list involves removing a node from the list and adjusting the pointers of the surrounding nodes to maintain the proper sequence. Deletion can be performed at the beginning, end, or any position within the list.
### Deletion at the beginning
**Approach:**
To delete a node from the start/beginning/front of a Linked List, follow these steps:
- If the Linked List is empty, print an error message and return.
- Store the head node in a temporary pointer.
- Update the head pointer to point to the next node of the head.
- Free the memory allocated for the temporary node.
- Decrement the size of the Linked List.

Here is the code implementation in C:
```c
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
```
### Deletion at the end
**Approach:**
To delete a node from the end of a Linked List, follow these steps:
- If the Linked List is empty, print an error message and return.
- If the Linked List has only one node, free the memory allocated for the node and set the head to NULL.
- Traverse the list to find the second-to-last node.
- Free the memory allocated for the last node and set the next pointer of the second-to-last node to NULL.

Here is the code implementation in C:
```c
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
```
### Deletion at the given position
**The delete_by_position function deletes the node at the specified position in the linked list.**

- The function takes a double pointer to the head of the linked list and the position of the node to be deleted as parameters.
- It first checks if the linked list is empty. If it is, it prints an error message and returns.
- Next, it checks if the position is 1. If it is, it calls the delete_from_head function to delete the node from the head of the linked list and prints a success message.
- Then, it checks if the position is equal to the size of the linked list. If it is, it calls the delete_from_tail function to delete the node from the tail of the linked list and prints a success message.
- it checks if the position is greater than the size of the linked list or less than 1. If it is, it prints an error message and returns.
- If none of the above conditions are met, it initializes a temporary pointer temp to the head of the linked list and a pointer prev to NULL.
- It then uses a loop to traverse the linked list until it reaches the node at the specified position. It keeps track of the current position using the variable k.
- Once the node at the specified position is found, it updates the next pointer of the previous node to skip the node to be deleted.
- It frees the memory allocated for the node to be deleted and sets the temp pointer to NULL.
- Finally, it decrements the size of the linked list, prints a success message, and returns.

Here is code implementaion
```c
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
```
### 3. `Traversal`
**Approch**
```c
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
```

### 4. `Reverse`
**Approach**

Follow the steps below to solve the problem:

- Initialize three pointers prev as NULL, curr as head, and next as NULL.
- Iterate through the linked list. In a loop, do the following:
- Before changing the next of curr, store the next node 
- next = curr -> next
- Now update the next pointer of curr to the prev 
  curr -> next = prev 
- Update prev as curr and curr as next 
  prev = curr 
  curr = next
  Below is the implementation of the above approach:

<img src="images/RGIF2.gif" alt="" width="25%" height="40%">


```c
void reverse_Linked_list_using_loop(Node **head)
{
    if(!head)
    {
        printf("Linked list is empty size -> %d\n",size);
        return;
    }
    if(!(*head)->next)
    {
        printf("Reverserd \n");
        return;
    }

    Node *prev = NULL, *curr = *head, *forward = curr->next;

    while(forward)
    {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = forward->next;
    }
    curr->next = prev;
    prev = curr;
    *head = prev;
}

void reverse_Linked_list_using_recursion(Node *curr, Node *prev, Node **head)
{
    if(curr == NULL)
    {
        return;
    }
    if(curr->next == NULL)
    {
        *head = curr;
        curr->next = prev;
        return;
    }

    Node *nextNode  = curr->next;
    curr->next = prev;
    reverse_Linked_list_using_recursion(nextNode,curr,head);
}
```