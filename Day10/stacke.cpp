#include <iostream>
#include <string.h>
#define size 100
using namespace std;
class postfixToInfix
{
  string arr;
  int top;

public:
  postfixToInfix()
  {
    top = -1;
  }
  int peek()
  {
    return arr[top];
  }
  int isEmpty()
  {
    if (top == -1)
      return 1;
    return 0;
  }
  void push(int item)
  {
    top++;
    arr[top] = item;
  }
  int pop()
  {
    return arr[top--];
  }
  int isDigit(int ch)
  {
    if (ch >= '0' && ch <= '9')
      return 1;
    else
      return 0;
  }
  int isOperator(char ch)
  {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
      return 1;
    else return 0;
  }
};