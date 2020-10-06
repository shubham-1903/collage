#include <iostream>
using namespace std;

int main()
{
  int r,c;
  int arr1[10][10];
  cin>>r>>c;
  cout<<"Matrix1: ";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr1[i][j];
    }
  }
  cout<<"Matrix2: ";
  int arr2[10][10];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr2[i][j];
    }
  }
  int arr[10][10];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      arr[i][j] = arr1[i][j];
      arr[i][j + c] = arr2[i][j];
    }
  }
  cout<<"Matrix1&2:\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < 2*c; j++)
    {
      cout << arr[i][j] <<" ";
    }
    cout<<endl;
  }
  return 0;
}