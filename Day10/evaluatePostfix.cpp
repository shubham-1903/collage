#include<iostream>
#include <string>
#include<math.h>
#include "stacke.cpp"
using namespace std;
int isDigit(char symbol)
{
  if(symbol>='0'&&symbol<='9') return 1;
  else return 0;
}


int isOperator(char symbol)
{
  if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' ||symbol=='-')
    return 1;
  else return 0;
}
int evaluate(char op,char i,char j)
{
  int a=(int)i;
  int b=(int)j;
  cout<<a<<" "<<b<<" e"<<endl;
  switch(op)
  {
    case '+':
      return a+b;
      break;
    case '-':
      return a-b;
      break;
    case '*':
      return a*b;
      break; 
    case '/':
      return a/b;
      break;    
    case '^':
      return pow(a,b);
      break;
    default:
      break;
  }
}
void evaluatePostfix(string s)
{
  Stack s1;
  string pf="";
  for(int i=0;i<s.length();i++)
  {
    if(isDigit(s[i])){
        s1.push((int)s[i]);
        s1.display();
    }
    else if(isOperator(s[i]))
    {
      char B=s1.pop();
      cout<<"b"<<B<<endl;
      char A=s1.pop();
      cout<<"a"<<A<<endl;
      int x=evaluate(s[i],B,A);
      s1.push((char)x);
      s1.display();
    }
  }
  char y;
  y =(char)s1.peak();
  cout<<"result: "<<y<<endl;
}

int main()
{
  string str="465*+3-";
  evaluatePostfix(str);
  return 0;
}