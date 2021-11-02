#include <iostream>
#include "my-queue.hpp"

int main() {
  MyQueue* mq = new MyQueue();
  mq->push(1);
  mq->push(2);
  int peek = mq->peek();
  mq->pop();
  bool empty = mq->empty();
  std::cout << (peek == 1 && !empty ? "PASS" : "FAIL") << std::endl;

  return 0;
}
