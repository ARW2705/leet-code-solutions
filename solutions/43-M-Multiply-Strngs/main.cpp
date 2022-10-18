#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

std::string getSum(std::string s1, std::string s2) {
  std::string runningSum = "";
  int sIndex = s1.size() - 1, pIndex = s2.size() - 1;
  int carry = 0, sum, digit;

  while (sIndex >= 0 || pIndex >= 0 || carry) {
    sum = carry;
    if (sIndex >= 0) sum += s1[sIndex--] - '0';
    if (pIndex >= 0) sum += s2[pIndex--] - '0';

    digit = sum % 10;
    carry = sum / 10;
    runningSum = std::to_string(digit) + runningSum;
  }

  return runningSum;
}

std::string getProduct(int num, std::string& str) {
  std::string productStr = "";
  int carry = 0, size = str.size(), product, digit;
  for (int i = 0; i < size; ++i) {
    product = num * (str[size - 1 - i] - '0') + carry;
    digit = product % 10;
    carry = product / 10;
    productStr = std::to_string(digit) + productStr;
  }

  if (carry > 0) {
    productStr = std::to_string(carry) + productStr;
  }

  return productStr;
}

std::string multiply(std::string num1, std::string num2) {
  if (num1.compare("0") == 0 || num2.compare("0") == 0) return "0";

  int size = num1.size();
  std::vector<std::string> memo(10, "");

  std::string runningSum = "", prodStr;
  for (int i = 0; i < size; ++i) {
    int num = num1[size - 1 - i] - '0';
    if (memo[num].size() == 0) {
      prodStr = getProduct(num, num2);
      memo[num] = prodStr;
    } else {
      prodStr = memo[num];
    }

    prodStr += std::string(i, '0');
    runningSum = getSum(runningSum, prodStr);
  }

  return runningSum;
}

int main() {
  std::string p1 = multiply("2", "3");
  // std::cout << p1 << "\n";
  printSuccess(p1.compare("6") == 0);

  std::string p2 = multiply("123", "456");
  // std::cout << p2 << "\n";
  printSuccess(p2.compare("56088") == 0);

  std::string p3 = multiply("123", "0");
  // std::cout << p3 << "\n";
  printSuccess(p3.compare("0") == 0);

  std::string p4 = multiply("1000000000000", "1000000000000");
  // std::cout << p4 << "\n";
  printSuccess(p4.compare("1000000000000000000000000") == 0);

  std::string p5 = multiply("999", "999");
  // std::cout << p5 << "\n";
  printSuccess(p5.compare("998001") == 0);

  std::string p6 = multiply("2925", "4787");
  // std::cout << p6 << "\n";
  printSuccess(p6.compare("14001975") == 0);

  return 0;
}
