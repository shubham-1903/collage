#include<iostream>
using namespace std;
int linearSearch(int* arr,int l,int r,int x)
{
  if(l>r) return -1;
  if(arr[l]==x) return l;
  if(arr[r]==x) return r;
  return linearSearch(arr,l+1,r-1,x);
}
int main()
{
  int *arr= new int(10);
  int n;
  cin>>n;
  for(int i=0;i<n; i++)
    cin>>arr[i];
  int value;
  cin>>value;
  int index=linearSearch(arr,0,n-1,value);
  cout<<"Value "<<value<<" found at index "<<index<<endl;
  return 0;
}