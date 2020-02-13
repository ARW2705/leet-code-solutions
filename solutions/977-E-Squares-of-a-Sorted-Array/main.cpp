#include <iostream>
#include <vector>
#include <cmath>

bool compareVectors(std::vector<int>& v1, std::vector<int>& v2) {
  if (v1.size() != v2.size()) return false;
  for (int i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

std::vector<int> sortedSquares(std::vector<int>& A) {
  std::vector<int> squared(A.size());
  int squaredIndex = squared.size() - 1;
  int left = 0;
  int right = A.size() - 1;
  while (left <= right) {
    if (std::abs(A[left]) > std::abs(A[right])) {
      squared[squaredIndex] = A[left] * A[left];
      ++left;
    } else {
      squared[squaredIndex] = A[right] * A[right];
      --right;
    }
    --squaredIndex;
  }
  return squared;
}

int main() {
  std::vector<int> test1 { -4, -1, 0, 3, 10 };
  std::vector<int> expected1 { 0, 1, 9, 16, 100 };
  std::vector<int> result1 = sortedSquares(test1);
  std::cout << (compareVectors(expected1, result1) ? "PASS": "FAIL") << "\n";

  std::vector<int> test2 { -7, -3, 2, 3, 11 };
  std::vector<int> expected2 { 4, 9, 9, 49, 121 };
  std::vector<int> result2 = sortedSquares(test2);
  std::cout << (compareVectors(expected2, result2) ? "PASS": "FAIL") << "\n";
  return 0;
}
