#include "q-stack.hpp"

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

MyStack::MyStack() {}

void MyStack::push(int x) {
  std::queue<int> tmp;
  int val;
  while (!q.empty()) {
    val = q.front();
    q.pop();
    tmp.push(val);
  }
  q.push(x);
  while (!tmp.empty()) {
    val = tmp.front();
    tmp.pop();
    q.push(val);
  }
}

int MyStack::pop() {
  int val = q.front();
  q.pop();
  return val;
}

int MyStack::top() {
  return q.front();
}

bool MyStack::empty() {
  return q.empty();
}
