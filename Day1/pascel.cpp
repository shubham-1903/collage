#include <iostream>
using namespace std;

int main()
{
  int row, c = 1, k, i, j;
  cout << "Input number of rows: ";
  cin >> row;
  for (i = 0; i < row; i++)
  {
    for (k = 1; k <= row - i; k++)
      cout << "**";
    for (j = 0; j <= i; j++)
    {
      if (j == 0 || i == 0)
        c = 1;
      else
        c = c * (i - j + 1) / j;
      cout << c << "$$$";
    }
    cout << endl;
  }
}
