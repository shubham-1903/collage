#include<iostream>
using namespace std;

int main()
{
  int arr[100]={2,5,6,4,3,3625,-2};
  int num;
  cin>>num;
  for(int i=0;i<num;i++)
  {
    cin>>arr[i];
  }
  int i=1;
  int largest=arr[0];
  int smallest=arr[0];
  while(arr[i]!=0)
  {
    if(largest<arr[i])
    {
      largest=arr[i];
    }
    if(smallest>arr[i])
    {
      smallest=arr[i];
    }
    i++;
  }
  cout<<"largest "<<largest<<"\n"<<"smallest "<<smallest;

  return 0;
}