#include<iostream>
using namespace std;

int add(int x,int y,int s)
{
  if(x+y==s)
    return 1;
  else
    return 0;
}

int main()
{
  int arr[100];
  int size,sum;

  cout<<"Enter size: ";
  cin>>size;

  cout<<"Sum: ";
  cin>>sum;

  for(int i=0;i<size;++i)
    cin>>arr[i];
  
  for(int i=0;i<size-1;i++){
    for(int j=i+1;j<size;j++){
      if(add(arr[i],arr[j],sum)==1){
        cout<<"pair: ";
        cout<<arr[i]<<" "<<arr[j]<<endl;
      }
      else{
      continue;
      }
    }
  }

  return 0;
}