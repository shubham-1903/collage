#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node()
  {
    data = 0;
    next = NULL;
  }
};
class stack
{
public:
  node *top;
  stack() { top = NULL; }
  void push(int x);
  int isEmpty();
  void pop();
  void display();
};
void stack::push(int data)
{
  node *temp = new node();

  if (!temp)
  {
    cout << "Stack Overflow";
    return;
  }
  temp->data = data;
  temp->next = top;
  top = temp;
}

int stack::isEmpty()
{
  return top == NULL;
}

void stack::pop()
{
  node *temp;
  if (top == NULL)
  {
    cout << "Stack Underflow" << endl;
    return;
  }
  else
  {
    temp = top;
    top = top->next;
    temp->next = NULL;
    delete(temp);
    cout<<"Item Popped"<< endl;
  }
}

void stack::display()
{
  node *temp;

  if (top == NULL)
  {
    cout << "Nothing to display..."<< endl;
    return;
  }
  else
  {
    temp = top;
    while (temp != NULL)
    {
      cout << temp->data << "-> ";
      temp = temp->next;
    }
  }
}
int main()
{
  stack s;
  int choice;
  do
  {
    cout << endl<<"Performing Operation"<< endl;
    cout << "\n1.Push an element\n2.Pop an element\n3.Display the stack\n0.Exit\n";
    cout << "\nEnter your choice ?";
    cin >> choice;
    switch (choice)
    {

    case 1:
      int item;
      cin >> item;
      s.push(item);
      break;
    case 2:
      s.pop();
      break;
    case 3:
      s.display();
      break;
    case 4:
      exit(0);
      break;
    default:
      cout << "Enter valid choice??"<< endl;
    }
  }while (choice != 0);
}