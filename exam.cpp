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
  void insertBeg(int);
  void insertEnd(int);
  void display();
  void deleteBeg();
};
void LinkedList:: insertBeg(int item)
{
  Node *curr=new Node;
  curr->data=item;
  curr->next=head;
  head=curr;
}
void LinkedList:: insertEnd(int item)
{
  Node* curr=new Node;
    curr->data=item;
    curr->next=NULL;
  if(head==NULL)
  {
    insertBeg(item);
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
  if(head==NULL){
    cout<<"No Node exits"<<endl;
    return;
  }
  else
  {
    Node* temp=head;
    head=head->next;
    delete(temp);
    cout<<"Node deleted from beginning"<<endl;
  }
}
void LinkedList:: display()
{
  if(head==NULL){
    cout<<"Linklist is empty"<<endl;
    return;
  }
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
    cout << "1. insertEnd()" << endl;
    cout << "2. deleteBeg()" << endl;
    cout << "3. display()" << endl;
    cout << "4. Clear Screen" << endl;
    cout<<"Enter operation number: ";
    cin >> option;
    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "Insert Node At end Operation \n\n Enter data of the Node to be inserted." << endl;
      cin >> data1;
      s.insertEnd(data1);
      break;

    case 2:
      s.deleteBeg();
      break;

    case 3:
      s.display();
      break;

    case 4:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
  return 0;
}