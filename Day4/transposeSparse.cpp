#include <iostream>
#include <stdlib.h>
#define M 100
#define N 100
using namespace std;

// void sparseMatrix(int b[M][N],int s)
// {

// }

int main()
{
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  int r, c;
  cout << "Enter row and column: ";
  cin >> r >> c;

  int arr[M][N];
  for (int i = 0; i < r; i++) //! user input matrix
    for (int j = 0; j < c; j++)
      cin >> arr[i][j];

  int size = 0; //! counting number of non zero element in matrix
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (arr[i][j] != 0)
        size++;

  system("cls");
  cout << "size: " << size << endl;
  int sparseArr[M][N], k = 0;

  sparseArr[0][k] = r;
  sparseArr[1][k] = c;
  sparseArr[2][k] = size;
  k++;

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (arr[i][j] != 0)
      {
        sparseArr[0][k] = i;
        sparseArr[1][k] = j;
        sparseArr[2][k] = arr[i][j];
        k++;
      }
  cout << "Sparse Matrix:\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << arr[i][j] << "  ";
    cout << endl;
  }
  cout << "1st" << endl;
  cout << "row\tcolumn\tsize" << endl;
  // cout << r << "\t" << c << "\t" << size << endl;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << sparseArr[j][i] << "\t";
    }
    cout << endl;
  }
  // --------------------------------------------------
  int arr2[M][N];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if(i==j)
        arr2[i][j]=arr[i][j];
      else
        arr2[i][j]=arr[j][i];
    }
  }

  int sparseArrTranspose[M][N], v = 0;

  sparseArrTranspose[0][v] = r;
  sparseArrTranspose[1][v] = c;
  sparseArrTranspose[2][v] = size;
  v++;

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (arr2[i][j] != 0)
      {
        sparseArrTranspose[0][v] = i;
        sparseArrTranspose[1][v] = j;
        sparseArrTranspose[2][v] = arr2[i][j];
        v++;
      }

  cout << "Sparse Matrix Transpose:\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << arr2[i][j] << "  ";
    cout << endl;
  }
  cout << "2nd" << endl;

  cout << "row\tcolumn\tsize" << endl;
  // cout << r << "\t" << c << "\t" << size << endl;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << sparseArrTranspose[j][i] << "\t";
    }
    cout << endl;
  }

  return 0;
}