#include <iostream>
#include <string>
#include <cmath>
#include "../../utilities/print-success.cpp"

int titleToNumber(std::string columnTitle) {
  int num = 0;
  int size = columnTitle.size();
  for (int i = 0; i < size; ++i) {
    num += (columnTitle[size - i - 1] - 'A' + 1) * static_cast<int>(std::pow(26, i));
  }
  return num;
}

int main() {
  printSuccess(titleToNumber("A") == 1);
  printSuccess(titleToNumber("AB") == 28);
  printSuccess(titleToNumber("ZY") == 701);
  printSuccess(titleToNumber("FXSHRXW") == 2147483647);
  return 0;
}
