#include <iostream>
using namespace std;

class Complex
{
  int real;
  int imag;

public:
  Complex() //!Default Constructor
  {
    real = 0;
    imag = 0;
  }
  Complex(int r, int im) //!Paremeterised Constructor
  {
    real = r;
    imag = im;
  }
  Complex(const Complex &c) //??? Copy Constructor
  {
    real = c.real;
    imag = c.imag;
  }
  void set(int r, int i) //?? Setting data on object Complex Type 
  {
    real = r;
    imag = i;
  }
  void display() //! Displaying Complex Data
  {
    if(imag<0)
      cout << real << " - i"<< -imag<<endl;
    else
      cout << real << " + i"<< imag<<endl;
  }
  Complex sum(Complex c) //?? Adding two object of Complex Type..
  {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
  }
};

int main()
{
  Complex c1,c2;
  int r1,i1,r2,i2;
  
  cin>>r1>>i1;
  cin>>r2>>i2;
  c1.set(r1,i1);
  c2.set(r2,i2);

  Complex c3;
  c3=c1.sum(c2);
  c3.display();
  return 0;
}