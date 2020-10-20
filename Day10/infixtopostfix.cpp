#include<iostream>
#include "stack.cpp"
using namespace std;
int precedence(char ch)
{

  if(ch=='^') return 3;
  else if(ch=='*' || ch=='/') return 2;
  else if(ch=='+' || ch=='-') return 1;
  else return 0;
}
void infixToPostfix(string s)
{
  Stack s1;
  string pf="";
  for(int i=0;i<s.length();i++)
  {
    if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
      pf+=s[i];
    }
    else if(s[i]=='('){
      s1.push(s[i]);
    }
    else if(s[i]==')'){
        while(s1.peak()!='('){
          int x=s1.pop();
            pf+=x;
        }
        if(s1.peak() == '(') 
            { 
              int c = s1.pop(); 
            } 
    }
    else {
      if(s1.isEmpty()){
        s1.push(s[i]);
      }
      else if(s1.peak()=='('){
        s1.push(s[i]);
      }
      else{
        if(precedence(s[i])>precedence(s1.peak())){
          s1.push(s[i]);
        }
        else{
          while((precedence(s[i])<=precedence(s1.peak()))&&!s1.isEmpty()){
            int x=s1.pop();
            pf+=x;
          }
          s1.push(s[i]);
        }
      }
    }

  }
  while(!s1.isEmpty()){
    pf+=s1.pop();
  }
    cout<<"pfff= "<<pf<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  int T;
  cin>>T;
  while(T--){
  string str;
  cin>>str;
  infixToPostfix(str);
  }
  // string str="a+((c-d)*e+f)*g*h";
  // infixToPostfix(str);
  return 0;
}