#include <iostream>
#include <stdlib.h>
#define M 100
#define N 100
using namespace std;

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

  sparseArr[0][k]=r;
  sparseArr[1][k]=c;
  sparseArr[2][k]=size;
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
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
      cout << arr[i][j] << "  ";
    cout << endl;
  }
  cout << "row\tcolumn\tsize" << endl;
  cout << r << "\t" << c << "\t" << size << endl;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << sparseArr[j][i] << "\t";
    }
    cout << endl;
  }
  cout << "\n\n";
  cout << "Compact Matrix row  : ";
  for (int i = 0; i < 1; i++)
  {
    for (int j = 0; j < 6; j++)
      cout << sparseArr[i][j] << "  ";
    cout << endl;
  }
  cout << "Compact Matrix Colum: ";

  for (int i = 1; i < 2; i++)
  {
    for (int j = 0; j < 6; j++)
      cout << sparseArr[i][j] << "  ";
    cout << endl;
  }
  cout << "Compact Matrix Value: ";

  for (int i = 2; i < 3; i++)
  {
    for (int j = 0; j < 6; j++)
      cout << sparseArr[i][j] << "  ";
    cout << endl;
  }

  return 0;
}