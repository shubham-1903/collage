#include<iostream>
using namespace std;
int volume(int a)
{
  return a*a*a;
}
double volume(int r,int h)
{
  return (3.14*r*r*h);
}
int volume(int x,int y,int z)
{
  return x*y*z;
}
int main()
{
  int cube;
  cout<<"Cube: ";
  cin>>cube;
  int cyl_r,cyl_h;
  cout<<"Cylinder: ";
  cin>>cyl_r>>cyl_h;
  cout<<"Rectagular Box: ";
  int l,b,h;
  cin>>l>>b>>h;

  cout<<"Cube: "<<volume(cube)<<endl;
  cout<<"Cylinder: "<<volume(cyl_r,cyl_h)<<endl;
  cout<<"Rectangle Box: "<<volume(l,b,h);
  return 0;
}
