#include <iostream>
using namespace std;
#define M 100
#define N 100

int main()
{

  int arr[M][N];
  int row, col, size;
  cin>>row>>size;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < row; j++)
    {
      cin>>arr[j][i];
    }
  cout<<arr[0][0]<<" row"; 
  int r=arr[0][0];
  int c=arr[0][1];
  int s=arr[0][2];
  int a[M][N];

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      a[i][j] = 0;

  for (int i = 0; i < size-1; i++)
  {
    for (int j = 0; i < row; j++)
    {
      int x=arr[i+1][j];

      int y=arr[i+1][j+1];
      int z=arr[i+1][j+2];
      a[x][y] = z;
      cout<<x<<y;
    }
  }

  cout << "Matrix" << endl;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}