//! Bubble sort is a simple algorithm which is used to sort a given set of n elements 
//! provided in form of an array with n number of elements. It compare all the element 
//! one by one and sort them based on their  values
//? -------------------------------------------------------------------------------
//! Insertion sort is a simple sorting algorithm that works similar to the way we sort 
// !playing cards in our hands. The array is virtually split into sorted and unsorted part. 
// !Values from the unsorted part are picked and placed at the correct position in the sorted part.
#include<iostream>
using namespace std;
void print(int arr[], int n)
{
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}
void swapNum(int *a,int*b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
void bubbleSort(int *arr, int n)
{
  int flag;
  for(int j=0;j<n;j++){
    flag=0;
    for(int i=0;i<n-j-1;i++){
      if(arr[i]>arr[i+1]){
        swapNum(&arr[i],&arr[i+1]);
        flag=1;
      }
    }
    cout<<"pass "<<j+1<<": ";
    print(arr,n);
    if(flag == 0)
      break;
  }
}
void insertionSort(int *arr,int n)
{
  int key,j;
  for(int i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
    cout<<"pass "<<i<<": ";
    print(arr,n);
  }
}
int minIndex(int *arr,int start,int end)
{
  int minElement=arr[start];
  int Index=start;
  for(int i=start;i<end;i++)
  {
    if(arr[i]<minElement){
      minElement=arr[i];
      Index=i;
    }
  }
  return Index;
}
void selectionSort(int *arr, int n)
{
  for(int i = 0; i < n; i++)
  {
    int smallest=minIndex(arr,i,n);
    swapNum(&arr[i],&arr[smallest]);
    cout<<"pass "<<i+1<<": ";
    print(arr,n);
  }
}
void stableSelectionSort(int *arr, int n)
{
  for(int i = 0; i < n; i++)
  {
    int smallest=minIndex(arr,i,n);
    int key=arr[smallest];
    for(int j=smallest;j>i; j--)
    {
      arr[j]=arr[j-1];
    }
    arr[i]=key;
    cout<<"pass "<<i+1<<": ";
    print(arr,n);
  }
}
void recursiveBubbleSort(int *arr, int n)
{
  if(n== 1) return;
  for(int i=0;i<n-1;i++)
    if(arr[i]>arr[i+1]) swapNum(&arr[i],&arr[i+1]);
  recursiveBubbleSort(arr,n-1);
}
void recursiveSelectionSort(int *arr, int n,int i)
{
  if(n==i) return;
  int smallest=minIndex(arr,i,n);
  swapNum(&arr[i],&arr[smallest]);
  recursiveSelectionSort(arr,n,i+ 1);
}
int main()
{
  int n;
  cin>>n;
  int *arr=new int(10);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  // bubbleSort(arr,n);
  // insertionSort(arr,n);
  // selectionSort(arr,n);
  // stableSelectionSort(arr,n);
  // recursiveBubbleSort(arr,n);
  recursiveSelectionSort(arr,n,0);
    print(arr,n);

}
