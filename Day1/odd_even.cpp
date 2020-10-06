#include<iostream>
using namespace std;

int main()
{
  int arr[1000]={1,2,3,4,5,6};
  int i=0;
  int even=0;
  int odd=0;
  while(arr[i]!=0)
  {
    if(arr[i]%2==0)
    {
      even+=arr[i];
    }
    else
    {
      odd+=arr[i];
    }
    i++;
  }
  cout<<"even "<<even<<"\n"<<"odd "<<odd;
  return 0;
}