#include <iostream>
#include <vector>
#include <stack>
#include "../../utilities/print-success.cpp"

bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
  std::stack<int> stack;
  stack.push(pushed[0]);
  int pushIndex = 1, popIndex = 0;
  int pushSize = pushed.size(), popSize = popped.size();
  while (pushIndex < pushSize || popIndex < popSize) {
    if (!stack.empty() && popped[popIndex] == stack.top()) {
      stack.pop();
      ++popIndex;
    } else if (pushIndex < pushSize) {
      stack.push(pushed[pushIndex]);
      ++pushIndex;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  std::vector<int> pushed1 = { 1, 2, 3, 4, 5 };
  std::vector<int> popped1 = { 4, 5, 3, 2, 1 };
  printSuccess(validateStackSequences(pushed1, popped1));

  std::vector<int> pushed2 = { 1, 2, 3, 4, 5 };
  std::vector<int> popped2 = { 4, 3, 5, 1, 2 };
  printSuccess(!validateStackSequences(pushed2, popped2));

  std::vector<int> pushed3 = { 1, 0 };
  std::vector<int> popped3 = { 1, 0 };
  printSuccess(validateStackSequences(pushed3, popped3));

  std::vector<int> pushed4 = { 3, 0, 1, 2 };
  std::vector<int> popped4 = { 2, 3, 1, 0 };
  printSuccess(!validateStackSequences(pushed4, popped4));

  return 0;
}
