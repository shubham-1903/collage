#include <iostream>
using namespace std;
#define M 100
#define N 100

int main()
{

  int arr[M][N];
  int row, col, size;
  cin>>row>>size;
  for (int i = 0; i <= size; i++)
    for (int j = 0; j < row; j++)
    {
      cin>>arr[i][j];
    }
  // cout<<arr[0][0]<<" row"; 
  int r=arr[0][0];
  int c=arr[0][1];
  int s=arr[0][2];
  int a[M][N];

  // for (int i = 0; i < r; i++)
  //   for (int j = 0; j < c; j++)
  //     a[i][j] = 0;
  int k=1;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      // int x=arr[i+1][j];

      // int y=arr[i+1][j+1];
      // int z=arr[i+1][j+2];
      // a[x][y] = z;
      if(i==arr[k][0]&&j==arr[k][1]){
        a[i][j]=arr[k][2];
        k++;
      }else{
        a[i][j]=0;
      }
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