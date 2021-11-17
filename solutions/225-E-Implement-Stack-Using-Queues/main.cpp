#include "q-stack.hpp"
#include "../../utilities/print-success.cpp"

int main() {
  MyStack* myStack = new MyStack();
  myStack->push(1);
  myStack->push(2);
  printSuccess(myStack->top() == 2);
  myStack->pop();
  printSuccess(!myStack->empty());

  MyStack* myStack2 = new MyStack();
  myStack2->push(1);
  myStack2->push(2);
  myStack2->push(3);
  printSuccess(myStack2->pop() == 3);
  printSuccess(myStack2->pop() == 2);
  printSuccess(myStack2->pop() == 1);
  printSuccess(myStack2->empty());

  return 0;
}
