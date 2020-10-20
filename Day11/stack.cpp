#include <iostream>
using namespace std;
#define MAX 100

class Stack
{
  char arr[MAX];
  int top;

public:
  Stack()
  {
    top = -1;
  }
  bool isFull()
  {
    if (top == MAX - 1)
      return true;
    else
      return false;
  }
  bool isEmpty()
  {
    if (top == -1)
      return true;
    else
      return false;
  }
  void push(char item)
  {
    top++;
    arr[top] = item;
  }
  char pop()
  {
    char x = arr[top];
    top--;
    return x;
  }
  char peak()
  {
    return arr[top];
  }
  void display()
  {
    cout << "--------------------" << endl;
    for(int i=top;i>=0;i--)
    {
      // cout<<"\t \t  "<<"-----"<<endl;
      // cout<<"\t| "<<arr[i]<<" |"<<endl;
      // cout<<"\t \t  "<<"-----"<<endl;
      cout<<arr[i]<<" ";
    }
    cout<< "\n--------------------";
  }
};