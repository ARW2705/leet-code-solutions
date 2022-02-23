#include <iostream>
#include <string>
#include <algorithm>
#include "../../utilities/print-success.cpp"

int minimumSum(int num) {
  std::string strNum = std::to_string(num);
  std::sort(strNum.begin(), strNum.end(), [](char& c1, char& c2) { return c1 < c2; });
  return (((strNum[0] - '0') * 10) + (strNum[2] - '0')) + (((strNum[1] - '0') * 10) + (strNum[3] - '0'));
}

int main() {
  printSuccess(minimumSum(2932) == 52); // 2239 -> 23 29
  printSuccess(minimumSum(4009) == 13); // 0049 -> 04 09
  printSuccess(minimumSum(1234) == 37); // 1234 -> 13 24

  return 0;
}
