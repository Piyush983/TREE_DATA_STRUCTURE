#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  int height; 
}; 
int max(int a, int b); 
int height(struct Node *N) 
{ 
  if (N == NULL) 
    return 0; 
  return N->height; 
} 
int max(int a, int b) 
{ 
  return (a > b)? a : b; 
} 
struct Node* newNode(int key) 
{ 
  struct Node* node = (struct Node*) 
            malloc(sizeof(struct Node)); 
  node->key = key; 
  node->left = NULL; 
  node->right = NULL; 
  node->height = 1;
  return(node); 
} 
struct Node *rightRotate(struct Node *y) 
{ 
  struct Node *x = y->left; 
  struct Node *T2 = x->right; 
  x->right = y; 
  y->left = T2; 
  y->height = max(height(y->left), height(y->right))+1; 
  x->height = max(height(x->left), height(x->right))+1; 
  return x; 
} 
struct Node *leftRotate(struct Node *x) 
{ 
  struct Node *y = x->right; 
  struct Node *T2 = y->left; 
  y->left = x; 
  x->right = T2; 
  x->height = max(height(x->left), height(x->right))+1; 
  y->height = max(height(y->left), height(y->right))+1; 
  return y; 
} 
int getBalanceFactor(struct Node *N) 
{ 
  if (N == NULL) 
    return 0; 
  return height(N->left) - height(N->right); 
} 
struct Node* insertNode(struct Node* node, int key) 
{ 
  if (node == NULL) 
    return(newNode(key)); 
  if (key < node->key) 
    node->left = insertNode(node->left, key); 
  else if (key > node->key) 
    node->right = insertNode(node->right, key); 
  else
    return node; 
  node->height = 1 + max(height(node->left), 
            height(node->right)); 
  int balanceFactor = getBalanceFactor(node); 
  if (balanceFactor > 1)
  {
    if (key < node->left->key)
    {
      return rightRotate(node);
    }
    else if (key > node->left->key)
    {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1)
  {
    if (key > node->right->key)
    {
      return leftRotate(node);
    }
    else if (key < node->right->key)
    {
      node->left = rightRotate(node->left);
      return leftRotate(node);
    }
  }
  
  return node; 
} 

void printPreOrder(struct Node *root) 
{ 
  if(root != NULL) 
  { 
    printf("%d ", root->key); 
    printPreOrder(root->left); 
    printPreOrder(root->right); 
  } 
} 
int main() 
{ 
struct Node *root = NULL; 
 root = insertNode(root, 10);
  root = insertNode(root, 20); 
  root = insertNode(root, 30); 
  root = insertNode(root, 40); 
 // root = insertNode(root, 25); 
  //root = insertNode(root, 61); 
  //root = insertNode(root, 8); 

  //root = insertNode(root, 11);  
 //
// root = insertNode(root, 50);  
printPreOrder(root);

} 

