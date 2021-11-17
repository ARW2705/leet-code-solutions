#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP

#include <stack>
#include <limits>

class MinStack {
public:
  MinStack();
  void push(int val);
  void pop();
  int top();
  int getMin();

private:
  std::stack<int> minStack;
  std::stack<int> tmpStack;
  int minVal;
};


#endif
