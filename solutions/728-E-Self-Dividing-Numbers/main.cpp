#include <iostream>
#include <vector>

bool compareVectors(std::vector<int>& v1, std::vector<int>& v2) {
  if (v1.size() != v2.size()) return false;
  for (int i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

bool canSelfDivide(int num) {
  int original = num;
  int digit = 0;
  while (num > 0) {
    digit = num % 10;
    if (digit == 0 || original % digit != 0) {
      return false;
    }
    num /= 10;
  }
  return true;
}

std::vector<int> selfDividingNumbers(int left, int right) {
  std::vector<int> result;
  result.reserve(right - left);
  for (int i=left; i <= right; ++i) {
    if (canSelfDivide(i)) {
      result.push_back(i);
    }
  }
  return result;
}

int main() {
  std::vector<int> result1 = selfDividingNumbers(1, 22);
  std::vector<int> expected1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22 };
  std::cout << (compareVectors(expected1, result1) ? "PASS": "FAIL") << "\n";
  return 0;
}
