#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string convertToTitle(int columnNumber) {
  std::string title = "";
  int mod;
  while (columnNumber > 0) {
    --columnNumber;
    mod = columnNumber % 26;
    title = static_cast<char>('A' + mod) + title;
    columnNumber /=26;
  }
  return title;
}

int main() {
  printSuccess(convertToTitle(26).compare("Z") == 0);
  printSuccess(convertToTitle(702).compare("ZZ") == 0);
  printSuccess(convertToTitle(676).compare("YZ") == 0);
  printSuccess(convertToTitle(1).compare("A") == 0);
  printSuccess(convertToTitle(28).compare("AB") == 0);
  printSuccess(convertToTitle(701).compare("ZY") == 0);
  printSuccess(convertToTitle(2147483647).compare("FXSHRXW") == 0);
  return 0;
}
