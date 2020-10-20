#include <iostream>
using namespace std;
#define MAX 5
class Queue
{
  int arr[MAX];
  int front;
  int rear;

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }
  void enQueue(int item)
  {
    rear++;
    arr[rear] = item;
  }
  int deQueue()
  {
    front++;
    return arr[front];
  }
  int peak()
  {
    return arr[front];
  }
  int isFull()
  {
    if (rear == MAX - 1)
      return 1;
    else
      return 0;
  }
  int isEmpty()
  {
    if (front == rear)
      return 1;
    else
      return 0;
  }
  void display()
  {
    for (int i = rear; i >= front + 1; i--)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Queue q1;
  cout << "Queue Operation: " << endl;
  cout << "1 for enQueue() " << endl;
  cout << "2 for deQueue() " << endl;
  cout << "3 for peak() " << endl;
  cout << "4 for isFull() " << endl;
  cout << "5 for isEmpty() " << endl;
  cout << "6 for display() " << endl;
  cout << "0 for exit from the program: " << endl;

  do
  {
    cout << "Enter Number key" << endl;
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
      if (q1.isFull())
        cout << "Queue is full" << endl;
      else
      {
        int x;
        cout << "Enter item: ";
        cin >> x;
        q1.enQueue(x);
      }
      break;
    case 2:
      if (!q1.isEmpty())
      {
        cout << "Item poped: " << q1.deQueue() << endl;
      }
      else
      {
        cout << "Queue is empty." << endl;
      }
      break;

    case 3:
      if (q1.isEmpty())
        cout << "Array is Empty" << endl;
      else
        cout << "Peak value is " << q1.peak() << endl;
      break;

    case 4:
      if (q1.isFull())
        cout << "Queue is full" << endl;
      else
        cout << "Queue is not full" << endl;
      break;

    case 5:
      if (q1.isEmpty())
        cout << "Queue is empty" << endl;
      else
        cout << "Queue is not empty" << endl;
      break;

    case 6:
      if (q1.isEmpty())
        cout << "Queue is empty" << endl;
      else
        q1.display();
      break;

    default:
      exit(1);
      break;
    }
  } while (1);
  return 0;
}