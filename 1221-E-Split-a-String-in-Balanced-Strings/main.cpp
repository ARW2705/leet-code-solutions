#include <iostream>
#include <string>

void printSuccess(int expected, int result) {
  std::cout << "For " << expected << " splits, got " << result << ": " << ((expected == result) ? "PASS": "FAIL") << "\n";
}

int balancedStringSplit(std::string& str) {
  int total = 0;
  int balance = 0;
  for (auto c : str) {
    balance += (c == 'L') ? -1: 1;
    total += (balance == 0);
  }
  return total;
}

int main() {
  std::string s1 = "RLRRLLRLRL";
  int expected1 = 4;
  printSuccess(expected1, balancedStringSplit(s1));

  std::string s2 = "RLLLLRRRLR";
  int expected2 = 3;
  printSuccess(expected2, balancedStringSplit(s2));

  std::string s3 = "LLLLRRRR";
  int expected3 = 1;
  printSuccess(expected3, balancedStringSplit(s3));

  std::string s4 = "RLRRRLLRLL";
  int expected4 = 2;
  printSuccess(expected4, balancedStringSplit(s4));

  return 0;
}
