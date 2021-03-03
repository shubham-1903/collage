#include <iostream>
using namespace std;
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

void preorderTraversal(node *r)
{
  if (r == NULL)
    return;
  cout << r->data << " ";
  preorderTraversal(r->lchild);
  preorderTraversal(r->rchild);
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
int main()
{
  int option, item;
  cout << "\t\tBinary Search Tree\t\t" << endl;
  cout << "1. insert()" << endl;
  cout << "2. preOrderTraversal()" << endl;
  cout<<"3. Total InternalNode()"<< endl;
  cout<<"4. Total ExternalNode()"<< endl;
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
      cout << "PreOrder traversal: ";
      preorderTraversal(root);
      cout << endl;
      break;
    case 3:
      cout << "Internal nodes: " << internalNode(root) << endl;
      break;
    case 4:
      cout << "External nodes: " << externalNode(root) << endl;
      break;
    case 0:
      break;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}