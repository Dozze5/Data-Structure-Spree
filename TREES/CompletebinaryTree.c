#include<stdio.h>
#include<stdlib.h>


typedef struct CompleteBinaryTreeNode {
    int key;
    struct CompleteBinaryTreeNode *left;
    struct CompleteBinaryTreeNode *right;
}TreeNode;

typedef struct QueueOfNodes{
    int front;
    int rear;
    int size;
    TreeNode **array;
}Queue;

TreeNode *newNode(int key)
{
    TreeNode *_new = (TreeNode *)malloc(sizeof(TreeNode));

    if(!_new)
    {
        printf("Memory Allocation Failure in newNode() (T_T) \n");
        exit(404);
        return NULL;
    }

    _new->key = key;
    _new->left = NULL;
    _new->right = NULL;

    return _new;
}

Queue *_init_Queue()
{
    Queue *_new = (Queue *)malloc(sizeof(Queue));

    if(!_new)
    {
        printf("Memory Allocation in Queue init() (T_T)\n");
        return NULL;
    }

    _new->front = _new->rear = -1;
    _new->size = 50;

    _new->array = (TreeNode **)malloc(_new->size * (sizeof(TreeNode *)));

    for(int i = 0; i < _new->size; i++)
    {
        _new->array[i] = NULL;
    }
    return _new;

}

int isFull(Queue *queue)
{
    return (queue->rear+1)%queue->size == queue->front;
}

int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

int onlyOneItem(Queue *queue)
{
    return queue->front == queue->rear;
}

void enqueue(TreeNode *node, Queue *queue)
{
    if(isFull(queue))
    {
        printf("Queue is Full \n");
        return;
    }
    if(isEmpty(queue))
    {
        queue->rear = 0;
        queue->front = 0;
    }
    else
    {
        queue->rear = (queue->rear+1)%queue->size;
    }
    queue->array[queue->rear] = node;
}

TreeNode *dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
        return NULL;
    }

    TreeNode *temp = queue->array[queue->front];
    if(onlyOneItem(queue))
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front+1)%queue->size;
    }
    return temp;
}

TreeNode *getFront(Queue *queue)
{
    return queue->array[queue->front];
}



void insert(TreeNode **root, Queue *queue,int key)
{
    TreeNode *_new = newNode(key);

    if(!*root)
    {
        *root = _new;
    }

    else
    {

        TreeNode *front = getFront(queue);

        if(!front->left)
        {
            front->left = _new;
        }

        else if(!front->right)
        {
            front->right = _new;
        }

        if(front && front->left && front->right)
        {
            dequeue(queue);
        }
    }

    enqueue(_new,queue);
}


void printInorder(TreeNode *root)
{
    if(root)
    {
        printInorder(root->left);
        printf("%d ", root->key);
        printInorder(root->right);
    }
}

void printPreorder(TreeNode *root)
{
    if(root)
    {
        printf("%d ", root->key);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(TreeNode *root)
{
    if(root)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->key);
    }
}

void levelOrder(TreeNode *root)
{
    Queue *queue = _init_Queue();

    enqueue(root,queue);

    while(!isEmpty(queue))
    {
        TreeNode *temp = dequeue(queue);

        printf("%d ",temp->key);

        if(temp->left)
        {
            enqueue(temp->left,queue);
        }

        if(temp->right)
        {
            enqueue(temp->right,queue);
        }
        
    }
}

void padding ( char ch, int n )
{
  int i;

  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void structure ( TreeNode *root, int level )
{
  int i;

  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->key );
    structure ( root->left, level + 1 );
  }
}


int main()
{
    TreeNode *root = NULL;
    Queue *queue = _init_Queue();

    for(int i = 1; i <= 12; ++i)
    {
        insert(&root, queue,i);
    }
    insert(&root,queue,13);

    printInorder(root);
    printf("\n");
    levelOrder(root);
    printf(("\n"));

    structure(root,0);

    return 0;
}