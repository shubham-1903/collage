#include<iostream>
using namespace std;
class Node{
  public:
    int data;
    Node *next;
  Node(){data=0;next=NULL;}
};
class LinkedList{
  public:
  Node* head;
  LinkedList(){head=NULL;}
  void prependNode(int);
  void appendNode(int);
  void display();
  void deleteBeg();
  void popNode();
  void reverse();
  int size();
  void insert(int);
};
void LinkedList:: prependNode(int item)
{
  Node *curr=new Node;
  curr->data=item;
  curr->next=head;
  head=curr;
}
void LinkedList:: appendNode(int item)
{
  Node* curr=new Node;
    curr->data=item;
    curr->next=NULL;
  if(head==NULL)
  {
    prependNode(item);
    return;
  }
  Node *temp=new Node;
  temp=head;
  while(temp->next!=NULL)
    temp=temp->next;

  temp->next=curr;
  return;
}
void LinkedList::deleteBeg()
{
  if(head==NULL)
    cout<<"No Node exits"<<endl;
  else
  {
    Node* temp=head;
    head=head->next;
    delete(temp);
  }
}
void LinkedList::insert(int item)
{
  Node* curr=new Node;
  curr->data=item;

  Node* temp=head, *prev;
  while(temp!=NULL && temp->data<item)
  {
    prev=temp;
    temp=temp->next;
  }
  if(temp==head)
  {
    curr->next=head;
    head=curr;
    return;
  }else{
    curr->next=prev->next;
    prev->next=curr;
    return;
  }
}
void LinkedList:: popNode()
{
  if(head==NULL)
    cout<<"NO Node exits"<<endl;
  else{
    Node* temp=head;
    Node *prevNode=NULL;
    while(temp->next!=NULL)
    {
      prevNode=temp;
      temp=temp->next;
    }
    prevNode->next=temp->next;
    delete temp;
  }
}
void LinkedList::reverse()
{
  Node* prevNode=NULL;
  Node* curNode=NULL;
  if(head!=NULL)
  {
    prevNode=head;
    head=head->next;
    curNode=head;
    prevNode->next=NULL;
    while(head!=NULL)
    {
      head=head->next;
      curNode->next=prevNode;
      prevNode=curNode;
      curNode=head;
    }
    head=prevNode;
  }
}
int LinkedList::size()
{
  Node* temp=head;
  int size=0;
  while(temp!=NULL)
  {
    size++;
    temp=temp->next;
  }
  return size;
}
void LinkedList:: display()
{
  if(head==NULL)
    cout<<"Linklist is empty"<<endl;
  Node* temp=head;
  while(temp!=NULL)
  {
    cout << "(" << temp->data << ")"
        << "-->";
    temp = temp->next;
  }
  cout << "NULL\n";
}
int main()
{
  LinkedList s;
  int option;
  int data1;
  do
  {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. deleteBeg()" << endl;
    cout << "4. popNode()" << endl;
    cout << "7. reverse()" << endl;
    cout << "5. display()" << endl;
    cout << "6. Clear Screen" << endl;

    cin >> option;
    Node *n1 = new Node();

    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter data of the Node to be Appended" << endl;
      cin >> data1;
      s.appendNode(data1);
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter data of the Node to be Prepended" << endl;
      cin >> data1;
      s.prependNode(data1);
      break;

    case 3:
      cout << " Node deleted at beginning: " << endl;
      s.deleteBeg();
      break;

    case 4:
      cout<<"Node deleted at end: "<<endl;
      s.popNode();
      break;
    case 7:
      cout<<"Reverse linklist: "<<endl;
      s.reverse();
    case 5:
      s.display();
      break;

    case 6:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
  return 0;
}