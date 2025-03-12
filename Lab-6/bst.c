#include <stdio.h>
#include <stdlib.h>

struct binarySearchtree
{
  int data;
  struct binarySearchtree *left;
  struct binarySearchtree *right;
};

struct binarySearchtree *insertion(struct binarySearchtree *root, int element)
{
  if (root == NULL)
  {
    root = (struct binarySearchtree *)malloc(sizeof(struct binarySearchtree));
    root->data = element;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  if (element < root->data)
    root->left = insertion(root->left, element);
  else
    root->right = insertion(root->right, element);

  return root;
}

void inorder(struct binarySearchtree *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main()
{
  struct binarySearchtree *root = NULL;

  root = insertion(root, 50);
  root = insertion(root, 30);
  root = insertion(root, 70);
  root = insertion(root, 20);
  root = insertion(root, 40);
  root = insertion(root, 60);
  root = insertion(root, 80);

  printf("In-order traversal: ");
  inorder(root);

  return 0;
}