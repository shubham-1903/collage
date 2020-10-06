#include<iostream>
using namespace std;

int main()
{
  int arr[100]={10,20,40,50,70};
  int size,k,i,j,num;
  cin>>size>>num>>k;
  for(i=size;i>size;i++)
  {
    arr[i]=arr[i-1];
  }
  arr[k]=num;
  j=0;
  while(arr[j]!=0)
  {
    cout<<arr[j]<<" ";
    j++;
  }

  return 0;
}