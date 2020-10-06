#include <iostream>
using namespace std;
#define MAX 5

class Stack
{
  int arr[MAX];
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
  void push(int item)
  {
    top++;
    arr[top] = item;
  }
  int pop()
  {
    int x = arr[top];
    top--;
    return x;
  }
  int peak()
  {
    return arr[top];
  }
  void display()
  {
    cout << "--------------------" << endl;
    for(int i=top;i>=0;i--)
    {
      // cout<<"\t \t  "<<"-----"<<endl;
      cout<<"\t| "<<arr[i]<<" |"<<endl;
      // cout<<"\t \t  "<<"-----"<<endl;
    }
    cout<< "--------------------" << endl;
  }
};

// int main()
// {
//   Stack s1;

//   cout << "Stack Operation: " << endl;
//   cout << "1 for push() " << endl;
//   cout << "2 for pop() " << endl;
//   cout << "3 for peak() " << endl;
//   cout << "4 for isFull() " << endl;
//   cout << "5 for isEmpty() " << endl;
//   cout << "6 for display() " << endl;
//   cout << "0 for exit from the program: " << endl;
//   do
//   {
//     cout << "Enter Number key" << endl;
//     int ch;
//     cin >> ch;
//     switch (ch)
//     {
//     case 1:
//       if (s1.isFull())
//         cout << "Array is full" << endl;
//       else
//       {
//         int x;
//         cout << "Enter item: ";
//         cin >> x;
//         s1.push(x);
//       }
//       break;
//     case 2:
//       if (!s1.isEmpty())
//       {
//         cout << "Item poped: " << s1.pop() << endl;
//       }
//       else
//       {
//         cout << "Array is empty." << endl;
//       }
//       break;

//     case 3:
//       if (s1.isEmpty())
//         cout << "Array is Empty" << endl;
//       else
//         cout << "Peak value is " << s1.peak() << endl;
//       break;

//     case 4:
//       if (s1.isFull())
//         cout << "YES" << endl;
//       else
//         cout << "NO" << endl;
//       break;

//     case 5:
//       if (s1.isEmpty())
//         cout << "YES" << endl;
//       else
//         cout << "NO" << endl;
//       break;

//     case 6:
//       if (s1.isEmpty())
//         cout << "Array is empty" << endl;
//       else
//         s1.display();
//       break;

//     default:
//       exit(1);
//       break;
//     }
//   } while (1);
//   return 0;
// }

//! 91630