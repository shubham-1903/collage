#include <iostream>
#include <stdlib.h>
using namespace std;
#define GLOBALSPACE 5
class node
{
public:
  node *lchild;
  int data;
  node *rchild;
};
node *newNode(int item)
{
  node *temp = new node;
  temp->data = item;
  temp->rchild = NULL;
  temp->lchild = NULL;
  return temp;
}

node *insert(node *r, int item)
{
  if (r == NULL)
    return newNode(item);
  else
  {
    node *temp = r;
    node *parent = NULL;

    while (temp != NULL)
    {
      parent = temp;
      if (item < temp->data)
        temp = temp->lchild;
      else
        temp = temp->rchild;
    }
    if (item < parent->data)
      parent->lchild = newNode(item);
    else
      parent->rchild = newNode(item);
  }
  return r;
}

void inorderTraversal(node *r)
{
  if (r == NULL)
    return;
  inorderTraversal(r->lchild);
  cout << r->data << " ";
  inorderTraversal(r->rchild);
}
void preorderTraversal(node *r)
{
  if (r == NULL)
    return;
  cout << r->data << " ";
  preorderTraversal(r->lchild);
  preorderTraversal(r->rchild);
}
void postorderTraversal(node *r)
{
  if (r == NULL)
    return;
  postorderTraversal(r->lchild);
  postorderTraversal(r->rchild);
  cout << r->data << " ";
}
int height(node *r)
{
  if (r == NULL)
    return -1;
  else
  {
    int lheight = height(r->lchild);
    int rheight = height(r->rchild);
    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

bool search(node *r, int n)
{
  if (r == NULL)
    return false;
  else
  {
    if (r->data == n)
      return true;
    else if (r->data < n)
      return search(r->rchild, n);
    else
      return search(r->lchild, n);
  }
}
int largest(node *r)
{
  if (r->rchild == NULL)
    return r->data;
  else
    return largest(r->rchild);
}
node* smallest(node *r)
{
  if (r->lchild == NULL)
    return r;
  else
    return smallest(r->lchild);
}
int externalNode(node *r)
{
  if (r == NULL)
    return 0;
  else if (r->lchild == NULL && r->rchild == NULL)
    return 1;
  else
    return externalNode(r->lchild) + externalNode(r->rchild);
}

int totalNode(node *r)
{
  if (r == NULL)
    return 0;
  else
    return 1 + totalNode(r->lchild) + totalNode(r->rchild);
}
int internalNode(node *r)
{
  return totalNode(r) - externalNode(r);
}

node *deleteNode(node *r, int item)
{
  if (r == NULL)
    return r;
  else if (item < r->data)
    r->lchild = deleteNode(r->lchild, item);
  else if (item > r->data)
    r->rchild = deleteNode(r->rchild, item);
  else
  {
    if (r->lchild == NULL)
    {
      node *temp = r->rchild;
      delete (r);
      return temp;
    }
    else if (r->rchild == NULL)
    {
      node *temp = r->lchild;
      delete (r);
      return temp;
    }
    else
    {
      node *temp = smallest(r->rchild);
      r->data = temp->data;
      r->rchild = deleteNode(r->rchild, temp->data);
    }
  }
  return r;
}
void print2D(node *r, int space)
{
  if (r == NULL)
    return;
  space = space + GLOBALSPACE;
  print2D(r->rchild, space);
  cout << endl;
  for (int i = GLOBALSPACE; i < space; i++)
    cout << " ";
  cout << r->data << endl;
  print2D(r->lchild, space);
}
int main()
{
  int option, item;
  cout << "\t\tBinary Search Tree\t\t" << endl;
  cout << "1. insert()" << endl;
  cout << "2. InorderTraversal()" << endl;
  cout << "3. PreorderTraversal()" << endl;
  cout << "4. PostorderTraversal()" << endl;
  cout << "5. Search()" << endl;
  cout << "6. Total InternalNode()" << endl;
  cout << "7. Total ExternalNode()" << endl;
  cout << "8. Total Nodes()" << endl;
  cout << "9. Smallest()" << endl;
  cout << "10. Largest()" << endl;
  cout << "11. Height()" << endl;
  cout << "12. Print BST()" << endl;
  cout << "13. Clear()" << endl;
  cout << "14. Delete Node()" << endl;
  node *root = NULL;
  do
  {
    cout << "Enter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
      cout << "Enter item: ";
      cin >> item;
      if (root == NULL)
        root = insert(root, item);
      else
        insert(root, item);
      break;
    case 2:
      if (root == NULL)
        cout << "BST Empty" << endl;
      cout << "Inorder traversal: ";
      inorderTraversal(root);
      cout << endl;
      break;
    case 3:
      if (root == NULL)
        cout << "BST Empty" << endl;
      cout << "Preorder Traversal: ";
      preorderTraversal(root);
      cout << endl;
      break;
    case 4:
      if (root == NULL)
        cout << "BST Empty" << endl;
      cout << "PostOrder Traversal: ";
      postorderTraversal(root);
      cout << endl;

      break;
    case 5:
      cin >> item;
      if (search(root, item))
        cout << "Found" << endl;
      else
        cout << "Not Found" << endl;
      break;
    case 6:
      cout << "Internal nodes: " << internalNode(root) << endl;

      break;
    case 7:
      cout << "External nodes: " << externalNode(root) << endl;

      break;
    case 8:
      cout << "Total nodes: " << totalNode(root) << endl;

      break;
    case 9:
      // node *temp = smallest(root);
      cout << "Smallest in BST: " << smallest(root)->data << endl;

      break;
    case 10:
      cout << "Largest in BST: " << largest(root) << endl;

      break;
    case 11:
      cout << "Height of BST: " << height(root) << endl;

      break;
    case 12:
      print2D(root, 1);

      break;
    case 13:
      system("cls");

      break;
    case 14:
      cout << "Enter item to be deleted: ";
      cin >> item;
      if(root == NULL) cout << "BST Empty"<< endl;
      else
        cout << "Node deleted with root value: "<<deleteNode(root, item)->data<< endl;
      break;
    case 0:
      break;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}