#include<iostream>
using namespace std;
#define MAX 30
class stack{
  int top;
  public:
  int data[MAX];
  stack(){top=-1;}
  void push(int x);
  void pop();
  int peak();
  void display();
  bool isEmpty();
  bool isFull();
};
bool stack::isEmpty()
{
  if(top==-1) return true;
  return false;
}
bool stack::isFull()
{
  if(top>=MAX-1) return true;
  return false;
}
void stack::push(int x)
{
  if (isFull()) cout<< "Stack Overflow";
  else data[++top]=x;
}
void stack::pop()
{
  if(isEmpty()) cout << "Stack Empty"<< endl;
  else
  {
    data[top]=-999;
    top--;
    cout<<"Item popped"<< endl;
  }
}
int stack::peak()
{
  if(isEmpty()) return -1;
  return data[top];
}
void stack::display()
{
  if(isEmpty()) cout << "Stack is Empty"<< endl;
  int temp=top;
  while(temp>=0)
  {
    cout << "\t"<<data[temp]<<endl;
    temp--;
  }
}
int main()
{
  stack s;
  cout << "Stack Operation: " << endl;
  cout << "1 for push() " << endl;
  cout << "2 for pop() " << endl;
  cout << "3 for peak() " << endl;
  cout << "4 for display() " << endl;
  cout << "0 for exit from the program: " << endl;

  do
  {
    cout << "Enter Operation Key: ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        int x;
        cout << "Enter item: ";
        cin >> x;
        s.push(x);
      break;
    case 2:
      s.pop();
      break;

    case 3:
      if (s.peak()==-1)
        cout << "Stack is Empty" << endl;
      else
        cout << "Peak value is " << s.peak() << endl;
      break;

    case 4:
        s.display();
      break;

    default:
      exit(1);
      break;
    }
  } while (1);
  return 0;
}