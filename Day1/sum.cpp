#include <iostream>
using namespace std;

int main()
{
  int sum = 0, n;
  cin >> n;
  while (n != 0)
  {
    sum += n % 10;
    n = n / 10;
  }
  cout << "sum is " << sum << endl;
  return 0;
}