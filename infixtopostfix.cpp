#include<iostream>
#include<stack>
using namespace std;
int precedence(char ch)
{
  if(ch == '^') return 3;
  else if (ch == '*' || ch == '/') return 2;
  else if (ch == '+' || ch == '-') return 1;
  else return -1;
}
bool isAlphabet(char ch)
{
  if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z')) return true;
  else return false;
}
void infixToPostfix(string s)
{
  stack<char> st;
  st.push('N');
  int l=s.length();
  string postfix="";
  for (int i = 0; i < l; i++)
  {
    if(isAlphabet(s[i])) postfix+=s[i];
    else if(s[i]=='(') st.push('(');
    else if(s[i]==')')
    {
      while(st.top()!='N'&&st.top()!='(')
      {
        char c=st.top();
        st.pop();
        postfix+=c;
      }
      if(st.top()=='(')
        st.pop(); //?
    }
    else
    {
      while(st.top()!='N'&& precedence(s[i])<=precedence(st.top()))
      {
        char c=st.top();
        st.pop();
        postfix+=c;
      }
      st.push(s[i]);
    }
  }
  while(st.top()!='N')
  {
    char c=st.top();
    st.pop();
    postfix+=c;
  }
  cout<<"Postfix expression: "<<postfix;
}
int main()
{
  string exp;
  cout<<"Enter Infix Expression: ";
  cin>>exp;
  infixToPostfix(exp);
  return 0;
// "a+b*(c^d-e)^(f+g*h)-i"
}