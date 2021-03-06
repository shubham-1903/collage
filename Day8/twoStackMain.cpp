#include <iostream>
#include "twoStack.cpp"
using namespace std;
#define MAX 10

int main()
{
  Stack s1, s2;

  cout << "Stack Operation: " << endl;
  cout << "1 for push() " << endl;
  cout << "2 for pop() " << endl;
  cout << "3 for peak() " << endl;
  cout << "4 for isFull() " << endl;
  cout << "5 for isEmpty() " << endl;
  cout << "6 for display() " << endl;
  cout << "0 for exit from the program: " << endl;
  do
  {
    cout << "Enter Number key" << endl;
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
      int x;
      cout << "Enter item: ";
      cin >> x;
      if (x % 2 == 0)
      {
        if (s1.isFull1())
          cout << "Stack 1 is full" << endl;
        else
          s1.push1(x);
      }
      else
      {
        if (s2.isFull2())
          cout << "Stack 2 is full" << endl;
        else
          s2.push2(x);
      }
      break;
    case 2:
      cout << "Enter 1 for pop() from stack 1" << endl;
      cout << "Enter 2 for pop() from stack 2" << endl;
      int y;
      cin >> y;
      if (y == 1)
      {
        if (s1.isEmpty1())
          cout << "Stack 1 is empty:" << endl;
        else
          cout << "POP1() " << s1.pop1() << endl;
      }
      else if (y == 2)
      {
        if (s2.isEmpty2())
          cout << "Stack 2 is empty:" << endl;
        else
          cout << "POP2() " << s2.pop2() << endl;
      }
      break;

    case 3:
      cout << "Enter 1 for peak() from stack 1" << endl;
      cout << "Enter 2 for peak() from stack 2" << endl;
      int z;
      cin >> z;
      if (z == 1)
      {
        if(s1.isEmpty1())  cout << "Stack 1 is empty:" << endl;
        else cout << "Peak1 value is " << s1.peak1() << endl;
      }
      else if (z == 2)
      {
        if(s2.isEmpty2()) cout << "Stack 2 is empty:" << endl;
        else cout << "Peak2 value is " << s2.peak2() << endl;
      }
      break;

    case 4:
      if (s1.isFull1())
        cout << "Stack 1 is full" << endl;
      if (s2.isFull2())
        cout << "Stack 2 is full" << endl;
      if (!s1.isFull1() && !s2.isFull2())
        cout << "Stack is not full" << endl;
      break;

    case 5:
      if (s1.isEmpty1())
        cout << "Stack 1 is empty" << endl;
      if (s2.isEmpty2())
        cout << "Stack 2 is empty" << endl;
      if (!s1.isEmpty1() && !s2.isEmpty2())
        cout << "Stack is not empty" << endl;

      break;

    case 6:
      cout << "Enter 1 for display1() from stack 1" << endl;
      cout << "Enter 2 for display2() from stack 2" << endl;
      int i;
      cin >> i;
      switch (i)
      {
      case 1:
        if (s1.isEmpty1())
          cout << "Stack 1 is empty" << endl;
        else
        {
          cout << "Even Stack: " << endl;
          s1.display1();
        }
        break;
      case 2:
        if (s2.isEmpty2())
          cout << "Stack 2 is empty" << endl;
        else
        {
          cout << "Odd Stack: " << endl;
          s2.display2();
        }
        break;
      default:
        cout << "Wrong choice." << endl;
        break;
      }
      break;

    default:
      exit(1);
      break;
    }
  } while (1);
  return 0;
}