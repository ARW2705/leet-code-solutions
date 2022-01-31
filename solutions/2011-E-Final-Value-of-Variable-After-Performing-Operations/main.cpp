#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

int finalValueAfterOperations(std::vector<std::string>& operations) {
  int x = 0;
  for (auto operation : operations) {
    x += operation[1] == '+' ? 1 : -1;
  }
  return x;
}

int main() {
  std::vector<std::string> v1 { "--X", "X++", "X++" };
  printSuccess(finalValueAfterOperations(v1) == 1);

  std::vector<std::string> v2 { "++X", "++X", "X++" };
  printSuccess(finalValueAfterOperations(v2) == 3);

  std::vector<std::string> v3 { "X++", "++X", "--X", "X--" };
  printSuccess(finalValueAfterOperations(v3) == 0);

  return 0;
}
