#include<iostream>
using namespace std;
#define MAX 1000
class queue{
  int front;
  int rear;
  public:
  queue(){front=-1;rear=-1;}
  int data[MAX];
  void enQueue(int x);
  void deQueue();
  void display();
  bool isFull();
  bool isEmpty();
};
bool queue::isEmpty()
{
  if(front==rear) return true;
  return false;
}
bool queue::isFull()
{
  if(rear==MAX-1) return true;
  return false;
}
void queue::enQueue(int x)
{
  if(isFull()) cout << "Queue Overflow"<< endl;
  ++rear;
  data[rear]=x;
}
void queue::deQueue()
{
  if(isEmpty())
  {
    cout<<"Queue Empty"<< endl;
    return;
  }
  ++front;
}
void queue::display()
{
  if(isEmpty()) {cout << "Nothing to display"<< endl;return;}
  int temp=rear;
  cout << "rear--> ";
  while(temp>=front+1)
  {
    cout <<"\t"<<data[temp];
    temp--;
  }
  cout<<"\t<--front"<< endl;
}
int main()
{
  queue q;
  cout << "Queue Operation: " << endl;
  cout << "1 for enQueue() " << endl;
  cout << "2 for deQueue() " << endl;
  cout << "4 for display() " << endl;
  cout << "0 for exit from the program: " << endl;

  do
  {
    cout << "Enter Operation Key: ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        int x;
        cout << "Enter item: ";
        cin >> x;
        q.enQueue(x);
      break;
    case 2:
      q.deQueue();
      break;

    case 4:
        q.display();
      break;

    default:
      exit(1);
      break;
    }
  } while (1);
  return 0;
}