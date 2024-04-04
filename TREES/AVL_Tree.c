#include <stdio.h>
#include <stdlib.h>

typedef struct AVL_Tree{
    int key;
    struct AVL_Tree *left, *right;
    int height;
}TreeNode;

TreeNode *newNode(int key){
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if(node == NULL){
        printf("Memory Error\n");
        exit(1);
    }
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int height(TreeNode *node){
    if(node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(TreeNode *node){
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

TreeNode *LL_Rotate(TreeNode *node){
    TreeNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    temp->height = 1 + (height(temp->left) > height(temp->right) ? height(temp->left) : height(temp->right));
    return temp;
}

TreeNode *RR_Rotate(TreeNode *node){
    TreeNode *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    temp->height = 1 + (height(temp->left) > height(temp->right) ? height(temp->left) : height(temp->right));
    return temp;
}

TreeNode *LR_Rotate(TreeNode *node){
    node->left = RR_Rotate(node->left);
    return LL_Rotate(node);
}

TreeNode *RL_Rotate(TreeNode *node){
    node->right = LL_Rotate(node->right);
    return RR_Rotate(node);
}

TreeNode *Insert(TreeNode *root,int data)
{
    if(root == NULL)
        return newNode(data);
    if(data < root->key)
        root->left = Insert(root->left,data);
    else if(data > root->key)
        root->right = Insert(root->right,data);
    else
        return root;
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    int balance = balanceFactor(root);
    if(balance > 1 && data < root->left->key)
        return LL_Rotate(root);
    if(balance < -1 && data > root->right->key)
        return RR_Rotate(root);
    if(balance > 1 && data > root->left->key)
        return LR_Rotate(root);
    if(balance < -1 && data < root->right->key)
        return RL_Rotate(root);
    return root;
}

TreeNode *minValueNode(TreeNode *node){
    TreeNode *current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

TreeNode *Delete(TreeNode *root,int data){
    if(root == NULL)
        return root;
    if(data < root->key)
        root->left = Delete(root->left,data);
    else if(data > root->key)
        root->right = Delete(root->right,data);
    else{
        if(root->left == NULL || root->right == NULL){
            TreeNode *temp = root->left ? root->left : root->right;
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else{
            TreeNode *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = Delete(root->right,temp->key);
        }
    }
    if(root == NULL)
        return root;
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    int balance = balanceFactor(root);
    if(balance > 1 && balanceFactor(root->left) >= 0)
        return LL_Rotate(root);
    if(balance > 1 && balanceFactor(root->left) < 0)
        return LR_Rotate(root);
    if(balance < -1 && balanceFactor(root->right) <= 0)
        return RR_Rotate(root);
    if(balance < -1 && balanceFactor(root->right) > 0)
        return RL_Rotate(root);
    return root;
}

void Inorder(TreeNode *root){
    if(root != NULL){
        Inorder(root->left);
        printf("%d ",root->key);
        Inorder(root->right);
    }
}

void printTree(TreeNode *root,int space){
    if(root == NULL)
        return;
    space += 10;
    printTree(root->right,space);
    printf("\n");
    for(int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n",root->key);
    printTree(root->left,space);
}

int main(){
    TreeNode *root = NULL;
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,30);
    root = Insert(root,40);
    root = Insert(root,50);
    root = Insert(root,25);
    printf("Inorder Traversal of AVL Tree: ");
    Inorder(root);
    printf("\n");
    root = Delete(root,30);
    printf("Inorder Traversal of AVL Tree after deletion of 30: ");
    Inorder(root);
    printf("\n");
    printTree(root,0);
    root = Insert(root,1);
    printf("Inorder Traversal of AVL Tree after insertion of 1: ");
    printTree(root,0);
    return 0;
}