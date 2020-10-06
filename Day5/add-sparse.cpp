#include <iostream>
using namespace std;
void printMatrix(int a[][100], int r, int c)
{
  cout << "Matrix:\n";
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
      cout << a[i][j] << "  ";
    cout << endl;
  }
}

void addSparse(int a[][100], int b[][100], int r1, int c1, int r2, int c2)
{
  int s1=0;
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      if (a[i][j] != 0)
        s1++;

  int s2=0;
  for (int i = 0; i < r2; i++)
    for (int j = 0; j < c2; j++)
      if (a[i][j] != 0)
        s2++;
}

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

int main()
{
  int a[100][100], b[100][100];
  int row_1, col_1, row_2, col_2;
  
  cout<<"Enter row and col:\n";
  cin>>row_1>>col_1;
  cout << "Enter Matrix 1st:\n";
  for (int i = 0; i < row_1; i++)
    for (int j = 0; j < col_1; j++)
      cin >> a[i][j];

  int size_1 = 0;
  for (int i = 0; i < row_1; i++)
    for (int j = 0; j < col_1; j++)
      if (a[i][j] != 0)
        size_1++;
  sparseMatrix(a,row_1,col_1,size_1);

  cout<<"Enter row and col:\n";
  cin>>row_2>>col_2;
  cout << "Enter Matrix 2nd:\n";
  for (int i = 0; i < row_2; i++)
    for (int j = 0; j < col_2; j++)
      cin >> b[i][j];

  int size_2 = 0;
  for (int i = 0; i < row_2; i++)
    for (int j = 0; j < col_2; j++)
      if (a[i][j] != 0)
        size_2++;
  sparseMatrix(b,row_2,col_2,size_2);
  
  if (row_1 != row_2 && col_1 != col_2)
  {
    cout << "Addition not possible........";
    return 0;
  }

  return 0;
}