#include <stack>
#include "./my-queue.hpp"

MyQueue::MyQueue() {}

void MyQueue::push(int x) {
  int num;
  while (!staQueue.empty()) {
    num = staQueue.top();
    staQueue.pop();
    tmpQueue.push(num);
  }
  staQueue.push(x);
  while (!tmpQueue.empty()) {
    num = tmpQueue.top();
    tmpQueue.pop();
    staQueue.push(num);
  }
}

int MyQueue::pop() {
  int num = staQueue.top();
  staQueue.pop();
  return num;
}

int MyQueue::peek() {
  return staQueue.top();
}

bool MyQueue::empty() {
  return staQueue.empty();
}
