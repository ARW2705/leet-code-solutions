#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string addStrings(std::string num1, std::string num2) {
  int carry = 0;
  int num1Index = num1.size() - 1;
  int num2Index = num2.size() - 1;
  std::string sumStr(std::max(num1.size(), num2.size()), ' ');
  int leftOperand = 0, rightOperand = 0, sum;
  for (int i = sumStr.size() - 1; i >= 0; --i) {
    leftOperand = (num1Index >= 0) ? num1[num1Index--] - '0' : 0;
    rightOperand = (num2Index >= 0) ? num2[num2Index--] - '0' : 0;
    sum = leftOperand + rightOperand + carry;
    if (sum > 9) {
      sumStr[i] = static_cast<char>((sum % 10) + '0');
      carry = sum / 10;
    } else {
      sumStr[i] = static_cast<char>(sum + '0');
      carry = 0;
    }
  }
  if (carry) {
    sumStr = static_cast<char>(carry + '0') + sumStr;
  }
  return sumStr;
}

int main() {
  std::string s1a = "11";
  std::string s1b = "123";
  printSuccess(addStrings(s1a, s1b).compare("134") == 0);

  std::string s2a = "456";
  std::string s2b = "77";
  printSuccess(addStrings(s2a, s2b).compare("533") == 0);

  std::string s3a = "0";
  std::string s3b = "0";
  printSuccess(addStrings(s3a, s3b).compare("0") == 0);

  std::string s4a = "1";
  std::string s4b = "9";
  printSuccess(addStrings(s4a, s4b).compare("10") == 0);

  return 0;
}
