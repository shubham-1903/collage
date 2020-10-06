#include<iostream>
using namespace std;

int main()
{
  int arr1[3][3],arr2[3][3];
  cout<<"Matrix:\n";
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>arr1[i][j];
    }
  }
  cout<<"Matrix Transpose:\n";
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i==j)
        arr2[i][j]=arr1[i][j];
      else
        arr2[i][j]=arr1[j][i];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<arr2[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}