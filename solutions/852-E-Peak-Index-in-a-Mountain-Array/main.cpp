#include <iostream>
#include <vector>
#include <string>

/*
Let's call an array A a mountain if the following properties hold:

    A.length >= 3
    There exists some 0 < i < A.length - 1
    such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
    A[A.length - 1]

Given an array that is definitely a mountain, return
any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ...
 > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1

Example 2:

Input: [0,2,1,0]
Output: 1

Note:
    3 <= A.length <= 10000
    0 <= A[i] <= 10^6
    A is a mountain, as defined above.
*/

std::string vectorToString(std::vector<int>& m) {
  std::string result = "[";
  for (size_t i=0; i < m.size(); ++i) {
    result += std::to_string(m[i]);
    if (i < m.size() - 1) {
      result += ", ";
    }
  }
  result += "]";
  return result;
}

void printResult(std::vector<int>& m, int expected, int result) {
  std::cout
    << "For mountain: "
    << vectorToString(m)
    << ", expected peak at "
    << expected
    << ", got "
    << result
    << (expected == result ? "\nPASS\n": "\nFAIL\n");
}

int peakIndexInMountainArray(std::vector<int>& A) {
  int maxIndex = 0;
  for (size_t i=0; i < A.size(); ++i) {
    if (A[i] > A[maxIndex]) {
      maxIndex = i;
    }
  }
  return maxIndex;
}

int main() {
  std::vector<int> m1 { 0, 1, 0 };
  printResult(m1, 1, peakIndexInMountainArray(m1));

  std::vector<int> m2 { 0, 2, 1, 0 };
  printResult(m2, 1, peakIndexInMountainArray(m2));

  std::vector<int> m3 { 0, 10, 5, 2 };
  printResult(m3, 1, peakIndexInMountainArray(m3));

  return 0;
}
