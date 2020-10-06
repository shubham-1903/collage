#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
  int arr[3][3];
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> arr[i][j];
    }
  }
  cout<<"Lower Triangular Matrix:"<<endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if(i>j)
          cout<<"0 ";
      else
          cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
    return 0;
}
