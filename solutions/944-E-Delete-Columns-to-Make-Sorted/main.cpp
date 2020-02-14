#include <iostream>
#include <vector>
#include <string>

int minDeletionSize(std::vector<std::string>& A) {
  int numNeededDeletions = 0;
  for (size_t i=0; i < A[0].size(); ++i) {
    for (size_t j=1; j < A.size(); ++j) {
      if (A[j][i] < A[j - 1][i]) {
        ++numNeededDeletions;
        break;
      }
    }
  }
  return numNeededDeletions;
}

int main() {
  std::vector<std::string> test1 { "cba", "daf", "ghi" };
  int result1 = minDeletionSize(test1);
  std::cout << result1 << ": " << (result1 == 1 ? "PASS": "FAIL") << "\n";

  std::vector<std::string> test2 { "a", "b" };
  int result2 = minDeletionSize(test2);
  std::cout << result2 << ": " << (result2 == 0 ? "PASS": "FAIL") << "\n";

  std::vector<std::string> test3 { "zyx", "wvu", "tsr" };
  int result3 = minDeletionSize(test3);
  std::cout << result3 << ": " << (result3 == 3 ? "PASS": "FAIL") << "\n";

  std::vector<std::string> test4 { "rrjk", "furt", "guzm" };
  int result4 = minDeletionSize(test4);
  std::cout << result4 << ": " << (result4 == 2 ? "PASS": "FAIL") << "\n";

  return 0;
}
