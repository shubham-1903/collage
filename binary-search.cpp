#include<iostream>
using namespace std;
int binarySearch(int* arr,int l,int r,int x)
{
  while(l<=r)
  {
    int mid=(l+r)/2;
    if(x==arr[mid]) return mid;
    if(x>arr[mid]) l=mid+1;
    else if(x<arr[mid]) r=mid-1;
  }
  return -1;
}
int binarySearchRec(int *arr, int l, int r, int x) 
{ 
  if (r >= l) 
  { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x)  return mid; 
        if (arr[mid] > x) return binarySearchRec(arr, l, mid-1, x); 
        return binarySearchRec(arr, mid+1, r, x); 
  } 
  return -1; 
} 
int main()
{
  int n;
  cin>>n;
  int* arr= new int[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int value;
  cin>>value;
  int index=binarySearch(arr,0,n-1,value);
  if(index==-1) cout << "No value found."<< endl;
  else cout<<"Value "<<value<<" found at index "<<index<<endl;
  int index2=binarySearchRec(arr,0,n-1,value);
  if(index2==-1) cout<<"No value found."<< endl;
  else cout<<"Value "<<value<<" found at index2 "<<index2<<endl;
  return 0;
}