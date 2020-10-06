#include <iostream>
using namespace std;

int main()
{
  int r,c;
  int arr1[10][10];
  cout<<"enter row col: ";
  cin>>r>>c;
  cout << "Enter array 1st: " << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr1[i][j];
    }
  }
  cout << "Enter array 2nd:\n";
  int arr2[10][10];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> arr2[i][j];
    }
  }
  int arr[3][3];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      arr[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  cout<<"Final matrix:"<<endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}