#include <iostream>
#include <string>
#include <limits>
#include "../../utilities/print-success.cpp"

std::string toHex(int num) {
  if (num == 0) {
    return "0";
  } else {
    const int hexBase = 16;
    char digits[hexBase] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    std::string hex = "";
    unsigned int unsignedNum = static_cast<unsigned int>(num);
    while (unsignedNum > 0) {
      int mod = unsignedNum % hexBase;
      hex = digits[mod] + hex;
      unsignedNum /= hexBase;
    }
    return hex;
  }
}

int main() {
  std::string s1 = toHex(26);
  std::cout << "1: " << s1 << "\n";
  printSuccess(s1.compare("1a") == 0);

  std::string s2 = toHex(-1);
  std::cout << "2: " << s2 << "\n";
  printSuccess(s2.compare("ffffffff") == 0);

  std::string s3 = toHex(0);
  std::cout << "3: " << s3 << "\n";
  printSuccess(s3.compare("0") == 0);

  std::string s4 = toHex(-2);
  std::cout << "4: " << s4 << "\n";
  printSuccess(s4.compare("fffffffe") == 0);

  std::string s5 = toHex(-17);
  std::cout << "5: " << s5 << "\n";
  printSuccess(s5.compare("ffffffef") == 0);

  std::string s6 = toHex(-2147483648);
  std::cout << "6: " << s6 << "\n";
  printSuccess(s6.compare("80000000") == 0);

  std::string s7 = toHex(-1147483648);
  std::cout << "7: " << s7 << "\n";
  printSuccess(s7.compare("bb9aca00") == 0);

  std::string s8 = toHex(std::numeric_limits<int>::max());
  std::cout << "8: " << s8 << "\n";
  printSuccess(s8.compare("7fffffff") == 0);

  std::string s9 = toHex(std::numeric_limits<int>::min());
  std::cout << "9: " <<  s9 << "\n";
  printSuccess(s9.compare("80000000") == 0);

  return 0;
}
