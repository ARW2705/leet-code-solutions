#include <iostream>
#include <vector>

bool compareVector(std::vector<int>& v1, std::vector<int>& v2) {
  if (v1.size() != v2.size()) return false;
  for (size_t i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

void printVector(std::vector<int>& v) {
  std::cout << "[";
  for (size_t i=0; i < v.size(); ++i) {
    std::cout << v[i];
    if (i < v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

std::vector<int> sortArrayByParityII(std::vector<int>& A) {
  std::vector<int> sorted(A.size());
  int evenIndex = 0;
  int oddIndex = 1;
  for (int i : A) {
    if (i % 2 == 0) {
      sorted[evenIndex] = i;
      evenIndex += 2;
    } else {
      sorted[oddIndex] = i;
      oddIndex += 2;
    }
  }
  return sorted;
}

int main() {
  std::vector<int> test { 4, 2, 5, 7 };
  std::vector<int> result = sortArrayByParityII(test);
  std::vector<int> expected = { 4, 5, 2, 7 };
  printVector(result);
  std::cout << (compareVector(expected, result) ? "PASS": "FAIL") << "\n";

  return 0;
}
