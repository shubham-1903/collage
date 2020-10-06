#include <iostream>
#include "stack.cpp"
using namespace std;
#define MAXIMUM 100
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int arr[MAXIMUM];
  int s;
  cin >> s;
  for (int i = 0; i < s; i++)
  {
    int x;
    cin >> x;
    arr[i] = x;
  }
  Stack s1, s2;
  for (int i = 0; i < s; i++)
  {
    if (arr[i] % 2 == 0)
      s1.push(arr[i]);
    else
      s2.push(arr[i]);
  }
  cout << "\nStack 1" << endl;
  s1.display();
  cout << "\nStack 2" << endl;
  s2.display();

  return 0;
}