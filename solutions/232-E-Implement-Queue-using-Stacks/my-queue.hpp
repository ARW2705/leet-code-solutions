#ifndef MY_QUEUE_HPP
#define MY_QUEUE_HPP

#include <stack>

class MyQueue {
public:
  MyQueue();
  void push(int x);
  int pop();
  int peek();
  bool empty();

  std::stack<int> tmpQueue;
  std::stack<int> staQueue;
};

#endif
