#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int d)
  {
    data = d;
    next = NULL;
  }
};

class Queue
{
public:
  node *front, *rear;
  Queue()
  {
    front = rear = NULL;
  }
  void enQueue(int x)
  {

    node *temp = new node(x);

    if (rear == NULL)
    {
      front = rear = temp;
      return;
    }

    rear->next = temp;
    rear = temp;
  }

  void deQueue()
  {

    if (front == NULL)
      return;

    node *temp = front;
    front = front->next;

    if (front == NULL)
      rear = NULL;

    delete (temp);
  }
  void display()
  {
    node *ptr;
    ptr = front;
    if (front == NULL)
    {
      cout<<"Empty queue"<< endl;
    }
    else
    {
      cout<<"\tQueue Values ....."<< endl;
      while (ptr != NULL)
      {
        cout<<"\t\t"<<ptr->data<< endl;
        ptr = ptr->next;
      }
    }
  }
};
int main()
{
  Queue q;
  int choice;
  while (choice != 4)
  {
    cout << endl<<"Performing Operation"<< endl;
    cout << "\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n";
    cout << "\nEnter your choice ?";
    cin >> choice;
    switch (choice)
    {

    case 1:
      int item;
      cin >> item;
      q.enQueue(item);
      break;
    case 2:
      q.deQueue();
      break;
    case 3:
      q.display();
      break;
    case 4:
      exit(0);
      break;
    default:
      cout << "Enter valid choice??"<< endl;
    }
  }
}