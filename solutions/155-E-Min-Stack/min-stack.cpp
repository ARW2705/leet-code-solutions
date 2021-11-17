#include "min-stack.hpp"

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

MinStack::MinStack() {
  minVal = std::numeric_limits<int>::max();
}

void MinStack::push(int val) {
  if (minVal > val) {
    minVal = val;
  }
  minStack.push(val);
}

void MinStack::pop() {
  int topVal = minStack.top();
  minStack.pop();
  if (minVal == topVal) {
    int newMinVal = std::numeric_limits<int>::max();
    int minStackVal;
    while (!minStack.empty()) {
      minStackVal = minStack.top();
      minStack.pop();
      tmpStack.push(minStackVal);
      if (minStackVal < newMinVal) {
        newMinVal = minStackVal;
      }
    }
    minVal = newMinVal;
    int tmpVal;
    while (!tmpStack.empty()) {
      tmpVal = tmpStack.top();
      tmpStack.pop();
      minStack.push(tmpVal);
    }
  }
}

int MinStack::top() {
  return minStack.top();
}

int MinStack::getMin() {
  return minVal;
}
