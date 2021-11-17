#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"

std::vector<int> plusOne(std::vector<int>& digits) {
  bool carry = false;
  for (int i = digits.size() - 1; i >= 0; --i) {
    if (digits[i] == 9) {
      digits[i] = 0;
      carry = true;
    } else {
      ++digits[i];
      carry = false;
      break;
    }
  }
  if (carry) {
    digits.insert(digits.begin(), 1);
  }
  return digits;
}

int main() {
  std::vector<int> v1 { 1, 2, 3 };
  std::vector<int> e1 { 1, 2, 4 };
  std::vector<int> r1 = plusOne(v1);
  printSuccess(compareVector(r1, e1));

  std::vector<int> v2 { 4, 3, 2, 1 };
  std::vector<int> e2 { 4, 3, 2, 2 };
  std::vector<int> r2 = plusOne(v2);
  printSuccess(compareVector(r2, e2));

  std::vector<int> v3 { 0 };
  std::vector<int> e3 { 1 };
  std::vector<int> r3 = plusOne(v3);
  printSuccess(compareVector(r3, e3));

  std::vector<int> v4 { 9 };
  std::vector<int> e4 { 1, 0 };
  std::vector<int> r4 = plusOne(v4);
  printSuccess(compareVector(r4, e4));

  return 0;
}
