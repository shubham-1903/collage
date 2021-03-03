#include <iostream>
using namespace std;
#define MAX 30
int s=1;
void print(int *a, int l,int h)
{
  for (int i = l; i <= h; i++)
    cout << a[i] << " ";
}
void merge(int *a, int l, int mid, int r)
{
  int i = l, j = mid + 1, k = l;
  int arr[MAX];
  while (i <= mid && j <= r)
  {
    if (a[i] <= a[j])
      arr[k++] = a[i++];
    else
      arr[k++] = a[j++];
  }
  while (i <= mid)
    arr[k++] = a[i++];
  while (j <= r)
    arr[k++] = a[j++];
  for (i = l; i <= r; i++)
    a[i] = arr[i];
  // print(a, l,r);
}
void mergeSort(int *arr, int left, int right)
{
  if (left >= right)
    return;
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
    
  mergeSort(arr, mid + 1, right);

  // cout << "Step " << s++ << " : ";
  merge(arr, left, mid, right);
}
int main()
{
  int n;
  cout<<"Enter Size: ";
  cin>>n;
  int *a= new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  mergeSort(a, 0, n - 1);
  cout<<"Merge Sort Final: "<<endl;
  print(a, 0,n-1);
  return 0;
}