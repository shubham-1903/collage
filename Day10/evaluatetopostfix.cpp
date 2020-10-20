#include <iostream>
#include <string.h>
#include "stacke.cpp"
#define size 100
using namespace std;
int main()
{
  postfixToInfix s1;
  string str;
  char item;
  int i, c = 0, A, B;
  cout << "Enter expression\n";
  cin >> str;
  for (i = 0; i < str.length(); i++, c++)
  {
    item = str[c];
    if (s1.isDigit(item))
      s1.push(item - 48);
    else if (s1.isOperator(item))
    {
      B = s1.pop();
      A = s1.pop();
      if (item == '*')
        s1.push(A * B);
      else if (item == '/')
        s1.push(A / B);
      else if (item == '+')
        s1.push(A + B);
      else if (item == '-')
        s1.push(A - B);
    }
  }
  cout << "Result: ";
  cout << s1.pop();

  return 0;
}
