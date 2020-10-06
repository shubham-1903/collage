#include <iostream>
using namespace std;
#define MAX 10

class Stack
{
  int arr[MAX];
  int top1;
  int top2;

public:
  Stack()
  {
    top1 = -1;
    top2 = MAX / 2 -1;
  }
  int isFull1(){
    if(top1==MAX/2-1) return 1;
    else return 0;
  }
  int isFull2(){
    if(top2==MAX/2) return 1;
    else return 0;
  }
  int isEmpty1()
  {
    if(top1==-1) return 1;
    else return 0;
  }
  int isEmpty2()
  {
    if(top2==MAX/2-1) return 1;
    else return 0;
  }
  void push1(int item)
  {
    top1++;
    arr[top1] = item;
    cout<<"Pushed at "<<top1++<<endl;
  }
  void push2(int item)
  {
    top2++;
    arr[top2] = item;
    cout<<"Pushed at "<<top2++<<endl;
  }
  int pop1()
  {
    int x = arr[top1];
    top1--;
    return x;
  }
  int pop2()
  {
    int x = arr[top2];
    top2--;
    return x;
  }
  int peak1()
  {
    return arr[top1];
  }
  int peak2()
  {
    return arr[top2];
  }
  void display1()
  {
    cout << "--------------------" << endl;
    for (int i = top1; i >= 0; i--)
    {
      // cout<<"\t \t  "<<"-----"<<endl;
      cout << "\t| " << arr[i] << " |" << endl;
      // cout<<"\t \t  "<<"-----"<<endl;
    }
    cout << "--------------------" << endl;
  }
  void display2()
  {
    cout << "--------------------" << endl;
    for (int i = top2; i >= MAX/2; i--)
    {
      // cout<<"\t \t  "<<"-----"<<endl;
      cout << "\t| " << arr[i] << " |" << endl;
      // cout<<"\t \t  "<<"-----"<<endl;
    }
    cout << "--------------------" << endl;
  }
};
