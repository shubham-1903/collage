// #include <iostream>
#include<bits/stdc++.h>
#include "stack.cpp"
using namespace std;
int precedence(char ch)
{

  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return 0;
}
bool isOperand(char ch)
{
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
  {
    return 1;
  }
  else
    return 0;
}
int isOperator(char symbol)
{
  if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    return 1;
  else
    return 0;
}
void infixToPrefix(string s)
{
  Stack prefix, op;
  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (isOperand(s[i]))
    {
      prefix.push(s[i]);
      cout << s[i] << endl;
    }
    else if (isOperator(s[i]))
    {
      if (op.isEmpty())
        op.push(s[i]);
      else if (s[i] == ')')
        op.push(s[i]);
      else if (precedence(s[i]) > precedence(op.peak()))
        op.push(s[i]);
      else
      {
        while (precedence(s[i]) < precedence(op.peak()))
        {
          prefix.push(op.pop());
          cout << s[i] << endl; 
        }
        op.push(s[i]);
      }
    }
    else if (s[i] == '(')
    {
      while (op.peak() != ')')
      {
        char c = op.pop();
        prefix.push(c);
      }
      int i = op.pop();
    }
  }
  while (!op.isEmpty())
  {
    prefix.push(op.pop());
  }
  prefix.display();
}
int main()
{
  string str = "(a*b)+(c*d)";
  infixToPrefix(str);

  return 0;
}