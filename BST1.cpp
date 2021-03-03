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

void inorderTraversal(node *r)
{
  if (r == NULL)
    return;
  inorderTraversal(r->lchild);
  cout << r->data << " ";
  inorderTraversal(r->rchild);
}
node* smallest(node *r)
{
  if (r->lchild == NULL)
    return r;
  else
    return smallest(r->lchild);
}
// node *deleteNode(node *r, int item)
// {
//   if (r == NULL)
//     return r;
//   else if (item < r->data)
//     r->lchild = deleteNode(r->lchild, item);
//   else if (item > r->data)
//     r->rchild = deleteNode(r->rchild, item);
//   else
//   {
//     if (r->lchild == NULL)
//     {
//       node *temp = r->rchild;
//       delete (r);
//       return temp;
//     }
//     else if (r->rchild == NULL)
//     {
//       node *temp = r->lchild;
//       delete (r);
//       return temp;
//     }
//     else
//     {
//       node *temp = smallest(r->rchild);
//       r->data = temp->data;
//       r->rchild = deleteNode(r->rchild, temp->data);
//     }
//   }
//   return r;
// }
node* deleteNode(node*root,int key)
{
	if(root==NULL)
	{
		cout<<"no element in tree\n";
		return root;
	}
	node *x=root;
	node *parent=NULL;
	while(x!=NULL  && x->data!=key)
	{
		parent=x;
		if(key<x->data)
			x=x->lchild;
		else
			x=x->rchild;
	}
	if(x==NULL)
	{
		cout<<"Item not found\n";
		return root;
	}
	if(x->lchild==NULL || x->rchild==NULL)
	{
		node *ptr=NULL;
		if(x->lchild==NULL)
			ptr=x->rchild;
		else
			ptr=x->lchild;
		if(parent==NULL)
		{
			delete(x);
			return ptr;
		}
		else
		{
			if(x==parent->lchild)
				parent->lchild=ptr;
			else
				parent->rchild=ptr;
			cout<<key<<" is deleted\n";
		}
	}
	else
	{
		node *succ=x->rchild;
		node *psucc=NULL;
		while(succ->lchild!=NULL)
		{
			psucc=succ;
			succ=succ->lchild;
		}
		x->data=succ->data;
		if(psucc!=NULL)
			psucc->lchild=succ->rchild;
		else
			x->rchild=succ->rchild;
		delete(succ);
		cout<<key<<" is deleted\n";
		return root;
	}
}
int main()
{
  int option, item;
  cout << "\t\tBinary Search Tree\t\t" << endl;
  cout << "1. insert()" << endl;
  cout << "2. InorderTraversal()" << endl;
  cout << "3. Delete Node()" << endl;
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