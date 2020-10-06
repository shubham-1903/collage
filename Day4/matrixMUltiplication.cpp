#include<iostream>
#include<stdlib.h>
using namespace std;
// #define M=2;
// #define N=3;
// #define P=3;

int main()
{
  system("cls");
  int r1,c1;
  cout<<"Row and column of first matrix\n";
  cin>>r1>>c1;
  int A[10][10];
  int B[10][10];
  int C[10][10];

  for(int i=0;i<r1;i++)
    for(int j=0;j<c1;j++)
      cin>>A[i][j];

  // ***********************************************
  int r2,c2;
  cout<<"Row and column of second matrix\n";
  cin>>r2>>c2;

  for(int i=0;i<r2;i++)
      for(int j=0;j<c2;j++)
        cin>>B[i][j];

  system("cls");

  cout<<"Matrix1:\n";
    for(int i=0;i<r1;i++){
      for(int j=0;j<c1;j++)
        cout<<A[i][j]<<"\t";
      cout<<"\n\n";
    }


  cout<<"Matrix2:\n";
    for(int i=0;i<r2;i++){
      for(int j=0;j<c2;j++)
        cout<<B[i][j]<<"\t";
      cout<<"\n\n";
    }
  if(c1!=r2){
    cout<<"Multiplication not Possible...........\n";
    return 0;
  }
  else{
    for(int i=0;i<r1;i++){
      for(int j=0;j<c1;j++){
        C[i][j]=0;
        for(int k=0;k<r2;k++){
          C[i][j]+= A[i][k] * B[k][j];
        }
      }
    }
  }
  cout<<"Multiplication\n";
  for(int i=0;i<r1;i++){
      for(int j=0;j<c2;j++)
        cout<<C[i][j]<<"  ";
      cout<<endl;
  }
  return 0;
}