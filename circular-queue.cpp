#include <iostream>
using namespace std;
#define MAX 1000
#define INT_MIN 0
#define INT_MAX 1

class circularQueue
{
  int arr[MAX];
  int front;
  int rear;

public:
  circularQueue()
  {
    front = 0;
    rear = 0;
  }
  void enQueue(int item)
  {
    rear = (rear + 1) % MAX;
    arr[rear] = item;
  }
  int deQueue()
  {
    front = (front + 1) % MAX;
    return arr[front];
  }
  int peak()
  {
    return arr[front];
  }
  int isFull()
  {
    if ((rear + 1) % MAX == front)
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
    if (rear >= front)
    {
      for (int i = front + 1; i <= rear; i++)
      {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
    else
    {
      cout<<endl;
      for (int i = front + 1; i < MAX; i++)
        cout << arr[i] << " ";
      for (int i = 0; i <= rear; i++)
        cout << arr[i] << " ";
    }
  }
};

int main()
{
  circularQueue q1;
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
