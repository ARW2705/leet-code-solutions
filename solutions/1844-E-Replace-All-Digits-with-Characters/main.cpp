#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string replaceDigits(std::string s) {
  for (int i = 1; i < s.size(); i += 2) {
    s[i] = s[i - 1] + s[i] - '0';
  }
  return s;
}

int main() {
  std::string s1 = "a1c1e1";
  std::string e1 = "abcdef";
  std::string r1 = replaceDigits(s1);
  printSuccess(r1.compare(e1) == 0);

  std::string s2 = "a1b2c3d4e";
  std::string e2 = "abbdcfdhe";
  std::string r2 = replaceDigits(s2);
  printSuccess(r2.compare(e2) == 0);

  return 0;
}
