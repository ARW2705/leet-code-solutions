#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"

int myAtoi(std::string s) {
  bool isNegative = false, hasNumberStarted = false, hasSign = false, hasZero = false;
  std::vector<int> trimmed;
  for (char c : s) {
    if (c == ' ') {
      if (hasNumberStarted || hasSign || hasZero) {
        break;
      }
    } else if (c == '-' || c == '+') {
      if (hasNumberStarted || hasSign || hasZero) {
        break;
      }
      hasSign = true;
      isNegative = c == '-';
    } else if (c == '0') {
      if (hasNumberStarted) {
        trimmed.push_back(0);
      }
      hasZero = true;
    } else if (c <= '9' && c > '0') {
      hasNumberStarted = true;
      trimmed.push_back(c - '0');
    } else {
      break;
    }
  }

  int maxInt = std::numeric_limits<int>::max();
  int minInt = std::numeric_limits<int>::min();
  if (trimmed.size() > 10) {
    return isNegative ? minInt : maxInt;
  }

  long long num = 0;
  long long places = 1;
  for (int i = trimmed.size() - 1; i >= 0; --i) {
    num += trimmed[i] * places;
    places *= 10;
  }

  bool isOverflow = num > static_cast<unsigned int>(maxInt) + (isNegative ? 1 : 0);
  if (isOverflow) {
    return isNegative ? minInt : maxInt;
  }

  return num * (isNegative ? -1 : 1);
}

int main() {
  std::string s1 = "42";
  int r1 = myAtoi(s1);
  std::cout << r1 << "\n";
  printSuccess(r1 == 42);

  std::string s2 = "   -42";
  int r2 = myAtoi(s2);
  std::cout << r2 << "\n";
  printSuccess(r2 == -42);

  std::string s3 = "4193 with words";
  int r3 = myAtoi(s3);
  std::cout << r3 << "\n";
  printSuccess(r3 == 4193);

  std::string s4 = "2147483647";
  int r4 = myAtoi(s4);
  std::cout << r4 << "\n";
  printSuccess(r4 == 2147483647);

  std::string s5 = "-2147483648";
  int r5 = myAtoi(s5);
  std::cout << r5 << "\n";
  printSuccess(r5 == -2147483648);

  std::string s6 = "2147483648";
  int r6 = myAtoi(s6);
  std::cout << r6 << "\n";
  printSuccess(r6 == 2147483647);

  std::string s7 = "-91283472332";
  int r7 = myAtoi(s7);
  std::cout << r7 << "\n";
  printSuccess(r7 == -2147483648);

  std::string s8 = "+-12";
  int r8 = myAtoi(s8);
  std::cout << r8 << "\n";
  printSuccess(r8 == 0);

  std::string s9 = "20000000000000000000";
  int r9 = myAtoi(s9);
  std::cout << r9 << "\n";
  printSuccess(r9 == 2147483647);

  std::string s10 = "-09-8";
  int r10 = myAtoi(s10);
  std::cout << r10 << "\n";
  printSuccess(r10 == -9);

  std::string s11 = "-09 8";
  int r11 = myAtoi(s11);
  std::cout << r11 << "\n";
  printSuccess(r11 == -9);

  std::string s12 = "3.14";
  int r12 = myAtoi(s12);
  std::cout << r12 << "\n";
  printSuccess(r12 == 3);

  std::string s13 = "3.";
  int r13 = myAtoi(s13);
  std::cout << r13 << "\n";
  printSuccess(r13 == 3);

  std::string s14 = "  -0012a12";
  int r14 = myAtoi(s14);
  std::cout << r14 << "\n";
  printSuccess(r14 == -12);

  std::string s15 = "00-42";
  int r15 = myAtoi(s15);
  std::cout << r15 << "\n";
  printSuccess(r15 == 0);

  std::string s16 = "00.0";
  int r16 = myAtoi(s16);
  std::cout << r16 << "\n";
  printSuccess(r16 == 0);

  std::string s17 = "-2147483649";
  int r17 = myAtoi(s17);
  std::cout << r17 << "\n";
  printSuccess(r17 == -2147483648);

  std::string s18 = "-6147483648";
  int r18 = myAtoi(s18);
  std::cout << r18 << "\n";
  printSuccess(r18 == -2147483648);

  std::string s19 = "0 123";
  int r19 = myAtoi(s19);
  std::cout << r19 << "\n";
  printSuccess(r19 == 0);

  std::string s20 = "  + 413";
  int r20 = myAtoi(s20);
  std::cout << r20 << "\n";
  printSuccess(r20 == 0);

  std::cout << std::endl;

  return 0;
}
