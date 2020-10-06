#include<iostream>
using namespace std;
int maximum(int m,int n){
  if(m>n)
    return m;
  else
    return n;
}
int main()
{
  int arr1[100],size1;
  int arr2[100],size2;
  cout<<"Enter array size: ";
  cin>>size1>>size2;
  cout<<"Coefficient of equation one: ";
  for(int i=0;i<size1;i++){
    int num;
    cin>>num;
  }
  cout<<endl<<"Coefficient of equation second: ";
  for(int i=0;i<size2;i++){
    int num;
    cin>>num;
  }
  cout<<"Equation 1st: ";
  for(int i=0;i<size1;i++){
    cout<<arr1[i]<<" ";
  }
  cout<<endl<<"Equation 2nd: ";

  for(int i=0;i<size2;i++){
    cout<<arr2[i]<<" ";
  }
  int size=maximum(size1,size2);
  return 0;
}