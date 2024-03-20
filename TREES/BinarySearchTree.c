#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
    int min;
    int max;
}pair;

typedef struct BinarySearchTree{
    int key;
    struct BinarySearchTree *left, *right;
}TreeNode;


TreeNode *_newNode(int key)
{
    TreeNode *_new = (TreeNode *)malloc(sizeof(TreeNode));

    if(!_new)
    {
        printf("Memory Allocation failure in _newNode() (T_T)\n");
        exit(404);
    }

    _new->key = key;
    _new->left = _new->right = NULL;

    return _new;
}

TreeNode *_insertNode(TreeNode *root, int key)
{
    TreeNode *_new  = _newNode(key);
    TreeNode *travel = root;

    if(!root)
    {
        return _new;
    }

    if(travel->key < key)
    {
        travel->right = _insertNode((travel->right) ,key);
    }
    if(travel->key > key)
    {
        travel->left = _insertNode((travel->left), key);
    }

    return root;
}

TreeNode *Searching(TreeNode *find, int key)
{
    if(!find)
    {
        printf("Not founded (T_T)\n");
        return NULL;
    }
    if(key > find->key)
    {
        return Searching(find->right,key);
    }
    if(key < find->key)
    {
        return Searching(find->left, key);
    }
    return find;
}

TreeNode *minNode(TreeNode *root)
{
    if(!root)
    {
        return NULL;
    }
    if(!root->left)
    {
        return root;
    }
    minNode(root->left);
}

TreeNode *maxNode(TreeNode *root)
{
    if(!root)
    {
        return NULL;
    }
    if(!root->right)
    {
        return root;
    }
    maxNode(root->right);
}

TreeNode *deletion(TreeNode *root, int key)
{
    if(!root)
    {
        return NULL;
    }

    if(key > root->key)
    {
        root->right = deletion(root->right, key);
    }
    else if(key < root->key)
    {
        root->left = deletion(root->left, key);
    }

    else
    {
        if(root->left == NULL)
        {
            return root->right;
        }
        else if(root->right == NULL)
        {
            return root->left;
        }
        
            TreeNode *min = minNode(root->right);
            root->key = min->key;
            root->right = deletion(root->right, min->key);
            free(min);
    }
    return root;
}

void inorder(TreeNode *Inorder)
{
    if(Inorder)
    {
        inorder(Inorder->left);
        printf("%d ",Inorder->key);
        inorder(Inorder->right);
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
    TreeNode *root;
    root = _insertNode(root,5);
    _insertNode(root,3);
    _insertNode(root,7);    
    _insertNode(root,4);    
    _insertNode(root,6);    
    _insertNode(root,2);    
    _insertNode(root,8); 
    _insertNode(root,10); 
    _insertNode(root,15); 
    _insertNode(root,12); 
    _insertNode(root,1); 
    _insertNode(root,11); 


    inorder(root);   

    // TreeNode *search = Searching(root, 8);

    // printf("\n%d",search->key);

    // structure(root ,0);


    // TreeNode *min = minNode(root);
    // printf("\n%d",min->key);

    // TreeNode *max = maxNode(root);
    // printf("\n%d",max->key);

    // deletion(root,6);
    // printf("\n");
    // structure(root ,0);

    root = deletion(root,root->key);
    root = deletion(root,15);

    // printf("\n");
    structure(root ,0);

}