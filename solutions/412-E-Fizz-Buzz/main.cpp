#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-vector.cpp"

std::vector<std::string> fizzBuzz(int n) {
  std::vector<std::string> result(n);
  std::string fb = "";
  for (int i = 1; i < n + 1; ++i) {
    if (i % 3 == 0) {
      fb += "Fizz";
    }
    if (i % 5 == 0) {
      fb += "Buzz";
    }
    if (fb.size() > 0) {
      result[i - 1] = fb;
      fb = "";
    } else {
      result[i - 1] = std::to_string(i);
    }
  }
  return result;
}

int main() {
  std::vector<std::string> r1 = fizzBuzz(3);
  printVector(r1);
  std::vector<std::string> r2 = fizzBuzz(5);
  printVector(r2);
  std::vector<std::string> r3 = fizzBuzz(15);
  printVector(r3);

  return 0;
}
