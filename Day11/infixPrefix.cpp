#include <bits/stdc++.h>
#include <vector>
#include <iterator>
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
void display(stack<char> p, stack<char> o)
{
  cout << "TEST:" << endl;
  while (!p.empty())
  {
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;
  cout << "TEST op:" << endl;
  while (!o.empty())
  {
    cout << o.top() << " ";
    o.pop();
  }
}
void infixPrefix(string s)
{
  stack<char> prefix, op;
  cout << s.length() << endl;
  for (int i = s.length() - 1; i >= 0; --i)
  {
    cout << s[i] << " ";
    if (s[i] == ')')
      op.push(s[i]);
    if (isOperand(s[i]))
      prefix.push(s[i]);
    if (isOperator(s[i]))
    {
      if (op.empty())
        op.push(s[i]);
      else if (op.top() == ')')
        op.push(s[i]);
      else if (precedence(s[i]) > precedence(op.top()))
        op.push(s[i]);
      else
      {
        while (precedence(s[i]) < precedence(op.top()))
        {
          char x = op.top();
          op.pop();
          prefix.push(x);
        }
        op.push(s[i]);
      }
    }
    if (s[i] == '(')
    {
      while (op.top() != ')')
      {
        char x = op.top();
        op.pop();
        prefix.push(x);
      }
      op.pop();
    }
  }
  while (!op.empty())
  {
    char x = op.top();
    op.pop();
    prefix.push(x);
  }
  // system("cls");
  cout << endl;

  cout << "Infix To Prefix Expression:" << endl;
  // while (!prefix.empty())
  // {
  //   cout << prefix.top() << " ";
  //   prefix.pop();
  // }
  display(prefix, op);
}
int main()
{
  // string str ="((a/b)*e)-(c^d)+t";
  string str ="(a+(b/c)*(d^e)-f)";
  cout << "l: " << str.length() << endl;
  infixPrefix(str);
  return 0;
}
