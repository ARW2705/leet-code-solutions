#include <iostream>
#include <vector>
#include "../../utilities/print-vector.cpp"
#include "../../utilities/compare-vectors.cpp"

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
  int leftIndex = 0;
  int rightIndex = numbers.size() - 1;
  int sum;
  while (true) {
    sum = numbers[leftIndex] + numbers[rightIndex];
    if (sum < target) {
      ++leftIndex;
    } else if (sum > target) {
      --rightIndex;
    } else {
      return std::vector<int> { leftIndex + 1, rightIndex + 1 };
    }
  }
}

int main() {
  std::vector<int> t1a { 2, 7, 11, 15 };
  int t1b = 9;
  std::vector<int> e1 { 1, 2 };
  std::vector<int> r1 = twoSum(t1a, t1b);
  printVector(r1);
  std::cout << (compareVector(e1, r1) ? "PASS" : "FAIL") << "\n\n";

  std::vector<int> t2a { 2, 3, 4 };
  int t2b = 6;
  std::vector<int> e2 { 1, 3 };
  std::vector<int> r2 = twoSum(t2a, t2b);
  printVector(r2);
  std::cout << (compareVector(e2, r2) ? "PASS" : "FAIL") << "\n\n";

  std::vector<int> t3a { -1, 0 };
  int t3b = -1;
  std::vector<int> e3 { 1, 2 };
  std::vector<int> r3 = twoSum(t3a, t3b);
  printVector(r3);
  std::cout << (compareVector(e3, r3) ? "PASS" : "FAIL") << "\n\n";
  std::cout << std::endl;
  return 0;
}
