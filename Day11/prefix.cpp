#include <bits/stdc++.h>
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
// void display(stack<char> p, stack<char> o)
// {
//   cout << "TEST:" << endl;
//   while (!p.empty())
//   {
//     cout << p.top() << " ";
//     p.pop();
//   }
//   cout << endl;
//   cout << "TEST op:" << endl;
//   while (!o.empty())
//   {
//     cout << o.top() << " ";
//     o.pop();
//   }
// }
void display(stack<char> p)
{
  cout << "TEST:" << endl;
  while (!p.empty())
  {
    cout << p.top() << " ";
    p.pop();
  }
}
string reverse(string s)
{
  stack<char> s1;
  for(int i=0;i<s.size();++i)
  {
    s1.push(s[i]);
  }
  string reverseStr="";
  while(!s1.empty())
  {
    if(s1.top()=='(')
    {
      s1.top()=')';
    }else if(s1.top()==')')
    {
      s1.top()='(';
    }
    reverseStr+=s1.top();
    s1.pop();
  }
  return reverseStr;
}
string convertPostfix(string p)
{
  cout<<"hello"<<endl;
  string pf="";
  stack<char> s2;
  for(int i=0;i<p.size();i++)
  {
    if(isOperand(p[i]))
      pf+=p[i];
    if(p[i]=='(')
      s2.push(p[i]);
    if(isOperator(p[i]))
    {
      if(s2.empty())
        s2.push(p[i]);
      // if(p[i]=='(')
      //   s2.push(p[i]);
      if(precedence(p[i])>precedence(s2.top()))
        s2.push(p[i]);
      else
      {
        while((precedence(p[i])<=precedence(s2.top()))&&!s2.empty())
        {pf+=s2.top();
        s2.pop();}
        s2.push(p[i]);
      }
    }
    if(p[i]==')')
    {
      while(s2.top()!='(')
      {
        pf+=s2.top();
        s2.pop();
      }
      s2.pop();
    }
  }
  while (!s2.empty())
  {
    pf+=s2.top();
    s2.pop();
  }
  // display(s2);
  // cout<<"pf:"<<pf<<endl;
  return pf;
}
// void infixPrefix(string s)
// {
//   string reverse_str=reverse(s);
//   string postfix=convertPostfix(reverse_str);
//   string prefix=reverse(postfix);
//   cout<<"prefix expression: "<<prefix<<endl;
//   cout<<"postfix expression: "<<postfix<<endl;
//   cout<<" expression: "<<reverse_str<<endl;
// }
int main()
{
  string s="(a+(b/c)*(d^e)-f)";
  // infixPrefix(str);
  cout<<s.size()<<endl;
  string reverse_str=reverse(s);
  cout<<" expression: "<<reverse_str<<endl;
  string postfix=convertPostfix(reverse_str);
  // convertPostfix(reverse_str);
  cout<<"postfix expression: "<<postfix<<endl;
  string prefix=reverse(postfix);
  cout<<"prefix expression: "<<prefix<<endl;
  return 0;
}