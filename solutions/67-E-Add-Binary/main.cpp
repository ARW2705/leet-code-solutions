#include <iostream>
#include <string>
#include <bitset>
#include "../../utilities/print-success.cpp"

std::string addBinary(std::string a, std::string b) {
  std::string sum = "";
  int aEnd = a.size() - 1;
  int bEnd = b.size() - 1;
  bool carry = false;
  while (aEnd >= 0 || bEnd >= 0) {
    if (aEnd >= 0 && bEnd >= 0) {
      if (a[aEnd] ^ b[bEnd]) {
        sum = (carry ? '0' : '1') + sum;
      } else {
        sum = (carry ? '1' : '0') + sum;
        carry = a[aEnd] == '1';
      }
      --aEnd;
      --bEnd;
    } else if (aEnd >= 0) {
      if (!carry) {
        sum = a[aEnd] + sum;
      } else {
        carry = a[aEnd] == '1';
        sum = (carry ? '0' : '1') + sum;
      }
      --aEnd;
    } else {
      if (!carry) {
        sum = b[bEnd] + sum;
      } else {
        carry = b[bEnd] == '1';
        sum = (carry ? '0' : '1') + sum;
      }
      --bEnd;
    }
  }
  if (carry) {
    sum = '1' + sum;
  }
  return sum;
}

int main() {
  std::string s1a = "11";
  std::string s1b = "1";
  std::string e1 = "100";
  std::string r1 = addBinary(s1a, s1b);
  printSuccess(e1.compare(r1) == 0);

  std::string s2a = "1010";
  std::string s2b = "1011";
  std::string e2 = "10101";
  std::string r2 = addBinary(s2a, s2b);
  printSuccess(e2.compare(r2) == 0);

  return 0;
}
