#include <iostream>
using namespace std;
#define M 10
#define N 10
void identicalMatrix(int a[M][N],int b[M][N],int r,int c)
{

}
int main()
{
  int row,col;
  cin>>row>>col;
  int arr1[M][N];
  cout << "Enter array 1st: "<<endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> arr1[i][j];
    }
  }
  cout << "Enter array 2nd:\n";
  int arr2[3][3];
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> arr2[i][j];
    }
  }
  int flag = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr1[i][j] != arr2[i][j])
      {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0)
    cout << "Identical Matrix...." << endl;
  else
    cout<<"Not Identical........";

  return 0;
}