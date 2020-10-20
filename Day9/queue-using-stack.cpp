#include <iostream>
#include "stack.cpp"
using namespace std;
class QueueStack
{
  int count;
  Stack s1, s2;

public:
  QueueStack()
  {
    count = 0;
  }
  void enQueue(int item)
  {
    s1.push(item);
  }
  int deQueue()
  {
    while (!s1.isEmpty())
    {
      s2.push(s1.pop());
    }
    return s2.pop();
  }
};

int main()
{
  QueueStack q;
  q.enQueue(5);
  q.enQueue(4);
  q.enQueue(3);
  q.enQueue(2);
  int x= q.deQueue();
  int y= q.deQueue();
  int z= q.deQueue();
  q.enQueue(1);
  int w= q.deQueue();

  cout<<x<<y<<z<<w;

  return 0;
}