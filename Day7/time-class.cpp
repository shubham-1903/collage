#include <iostream>
using namespace std;

class Time
{
  int hours;
  int minutes;

public:
  Time add(Time t) //! Adding two object of Time class
  {
    Time temp;
    temp.hours = hours + t.hours;
    temp.minutes = minutes + t.minutes;
    if(temp.minutes>=60){
      temp.hours+=temp.minutes/60;
      temp.minutes%=60;
    }

    return temp;
  }

  void setTime(int h, int m)
  {
    hours = h;
    minutes = m;
  }
  void showTime()
  {
    cout <<hours<<"hrs"<<" "<<minutes<<"min";
    cout << endl;
  }
};

int main()
{
  Time t1, t2;
  int hrs_1, min_1;
  cin >> hrs_1 >> min_1;
  t1.setTime(hrs_1, min_1);

  int hrs_2, min_2;
  cin >> hrs_2 >> min_2;
  t2.setTime(hrs_2, min_2);

  t1.showTime();
  t2.showTime();

  Time t3;
  t3 = t1.add(t2);

  cout << "Add time data: ";
  t3.showTime();
  return 0;
}