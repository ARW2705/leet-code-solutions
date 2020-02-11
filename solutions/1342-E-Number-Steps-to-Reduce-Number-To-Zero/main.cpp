#include <iostream>

int numberOfSteps(int num) {
  int steps = 0;
  while (num > 0) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num--;
    }
    ++steps;
  }
  return steps;
}

int main() {
  int result1 = numberOfSteps(14);
  std::cout << "To reduce 14 to 0 takes 6 steps, got " << result1 << (result1 == 6 ? "\nPASS\n": "\nFAIL\n");

  int result2 = numberOfSteps(8);
  std::cout << "To reduce 8 to 0 takes 4 steps, got " << result2 << (result2 == 4 ? "\nPASS\n": "\nFAIL\n");

  int result3 = numberOfSteps(123);
  std::cout << "To reduce 123 to 0 takes 12 steps, got " << result3 << (result3 == 12 ? "\nPASS\n": "\nFAIL\n");

  return 0;
}
