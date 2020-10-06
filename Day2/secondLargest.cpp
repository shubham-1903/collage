#include<iostream>
using namespace std;
int largestNum(int x,int y){
  if(x>y){
    return x;
  }
  else{
    return y;
  }
}
int main()
{
  int arr[100],size;
  cout<<"Enter array size: ";
  cin>>size;
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  int largest = -99;
  int secondLargest = -99;

  int j=0;
  while(arr[j]!=0){
    largest = largestNum(largest,arr[j]);
    j++;
  }
  cout<<"largest: "<<largest<<endl;
  int k=0;
  while(arr[k]!=0){
    if(largest!=arr[k]){
      secondLargest=largestNum(secondLargest,arr[k]);
    }
    k++;
  }
  cout<<"second largest: "<<secondLargest;
  return 0;
}