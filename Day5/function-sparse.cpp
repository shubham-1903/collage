#include <iostream>
#include<stdlib.h>
using namespace std;
#define M = 10;
#define N = 10;

void sparseMatrix(int a[][100],int r,int c,int s)
{
  int sparseArr[10][10], k = 0;

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (a[i][j] != 0)
      {
        sparseArr[0][k] = i;
        sparseArr[1][k] = j;
        sparseArr[2][k] = a[i][j];
        k++;
      }

  cout << "Compact Matrix row  : ";
  for (int i = 0; i < 1; i++)
  {
    for (int j = 0; j < s; j++)
      cout << sparseArr[i][j] << "  ";
    cout << endl;
  }

  cout << "Compact Matrix Colum: ";
  for (int i = 1; i < 2; i++)
  {
    for (int j = 0; j < s; j++)
      cout << sparseArr[i][j] << "  ";
    cout << endl;
  }

  cout << "Compact Matrix Value: ";
  for (int i = 2; i < 3; i++)
  {
    for (int j = 0; j < s; j++)
      cout << sparseArr[i][j] << "  ";
    cout << endl;
  }
}

void printMatrix(int a[][100],int r,int c)
{
  cout << "Orignal Matrix:\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << a[i][j] << "  ";
    cout << endl;
  }
}

int main()
{
  system("cls");
  int row,col;
  cout<<"Enter row and col: ";
  cin>>row>>col;
  int arr[100][100];
  cout <<"Enter Matrix:\n";
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      cin >> arr[i][j];

  int size = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (arr[i][j] != 0)
        size++;

  system("cls");
  printMatrix(arr,row,col);
  sparseMatrix(arr,row,col,size);


  return 0;
}