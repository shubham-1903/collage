#include<iostream>
using namespace std;

int main()
{
  int arr[100],size;
  cout<<"Enter array size: ";
  cin>>size;
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  int deleteNum,pos=0;
  cout<<"Which Number to delete: ";
  cin>>deleteNum;
  for(int i=0;i<size;i++){
    if(arr[i]==deleteNum)
      pos=i;
  }
  cout<<"pos: "<<pos<<endl;
  arr[pos]=0;
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  for(int i=pos;i<size;i++){
    arr[i]=arr[i+1];
  }
  for(int i=0;i<size-1;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}