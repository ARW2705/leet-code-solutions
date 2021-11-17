#include <iostream>
#include "min-stack.hpp"
#include "../../utilities/print-success.cpp"

int main() {
  MinStack* minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-3);
  printSuccess(minStack->getMin() == -3);
  minStack->pop();
  printSuccess(minStack->top() == 0);
  printSuccess(minStack->getMin() == -2);

  return 0;
}
