#ifndef Q_STACK_HPP
#define Q_STACK_HPP

#include <iostream>
#include <queue>

class MyStack {
public:
  MyStack();
  void push(int x);
  int pop();
  int top();
  bool empty();

private:
  std::queue<int> q;
};

#endif
