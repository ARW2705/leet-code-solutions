#include <iostream>
#include <vector>
#include <string>

std::string vectorToString(const std::vector<int>& v) {
  std::string printable = "[";
  for (int i=0; i < v.size(); ++i) {
    printable += std::to_string(v[i]);
    if (i < v.size() - 1) {
      printable += ", ";
    }
  }
  printable += "]";
  return printable;
}

bool compareVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
  if (v1.size() != v2.size()) return false;
  for (int i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) return false;
  }
  return true;
}

void printResult(std::vector<int> input, std::vector<int>& expected, std::vector<int> result) {
  std::cout
    << "For     "
    << vectorToString(input)
    << ", \nexpected "
    << vectorToString(expected)
    << ", \ngot     "
    << vectorToString(result)
    << "\n"
    << (compareVectors(expected, result) ? "PASS": "FAIL")
    << "\n";
}

std::vector<int> sortArrayByParity(std::vector<int> A) {
  int evens = 0;
  int odds = A.size() - 1;
  while (evens < odds) {
    if (A[evens] % 2 == 1 && A[odds] % 2 == 0) {
      int tmp = A[evens];
      A[evens] = A[odds];
      A[odds] = tmp;
    }
    evens += A[evens] % 2 == 0;
    odds -= A[odds] % 2 == 1;
  }
  return A;
}

int main() {
  std::vector<int> ex { 3, 1, 2, 4 };
  std::vector<int> expected { 4, 2, 1, 3 };
  printResult(ex, expected, sortArrayByParity(ex));
  return 0;
}
