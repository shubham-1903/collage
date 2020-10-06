#include <iostream>
#include "stack.cpp"
using namespace std;
#define MAXIMUM 20
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
  Stack s1;
  for (int i = 0; i < s; i++)
  {
    s1.push(arr[i]);
  }
  s1.display();
  for (int i = 0; i < s; i++)
  {
    arr[i] = s1.pop();
  }
  cout << "\nReverse array using stack" << endl;
  for (int i = 0; i < s; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}