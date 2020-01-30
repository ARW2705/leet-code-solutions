#include <iostream>
#include <vector>

std::string matrixToString(std::vector<std::vector<int>>& matrix) {
  std::string printable = "[";
  for (int i=0; i < matrix.size(); ++i) {
    printable.push_back('[');
    for (int j=0; j < matrix[i].size(); ++j) {
      printable += std::to_string(matrix[i][j]);
      if (j < matrix[i].size() - 1) {
        printable += ", ";
      }
    }
    printable += "]";
    if (i < matrix.size() - 1) {
      printable.push_back(',');
    }
  }
  printable.push_back(']');
  return printable;
}

bool compareMatrices(std::vector<std::vector<int>>& m1, std::vector<std::vector<int>>& m2) {
  if (m1.size() != m2.size()) return false;
  for (int i=0; i < m1.size(); ++i) {
    if (m1[i].size() != m2[i].size()) return false;
    for (int j=0; j < m1[i].size(); ++j) {
      if (m1[i][j] != m2[i][j]) return false;
    }
  }
  return true;
}

void printResult(std::vector<std::vector<int>>& input, std::vector<std::vector<int>>& expected, std::vector<std::vector<int>> result) {
  std::cout
    << "For      "
    << matrixToString(input)
    << ", \nexpected "
    << matrixToString(expected)
    << ", \ngot      "
    << matrixToString(result)
    << "\n"
    << (compareMatrices(expected, result) ? "PASS": "FAIL")
    << "\n";
}

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
    for (std::vector<int>& v : A) {
        for (int i=0; i < (v.size() + 1) / 2; ++i) {
            int tmp = v[i];
            v[i] = v[v.size() - i - 1] ^ 1;
            if (i < v.size() / 2) {
                v[v.size() - i - 1] = tmp ^ 1;
            }
        }
    }
    return A;
}

int main() {
  std::vector<std::vector<int>> ex1 {
    { 1, 1, 0 },
    { 1, 0, 1 },
    { 0, 0, 0 }
  };
  std::vector<std::vector<int>> expected1 {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 1, 1, 1 }
  };
  printResult(ex1, expected1, flipAndInvertImage(ex1));

  std::vector<std::vector<int>> ex2 {
    { 1, 1, 0, 0 },
    { 1, 0, 0, 1 },
    { 0, 1, 1, 1 },
    { 1, 0, 1, 0 }
  };
  std::vector<std::vector<int>> expected2 {
    { 1, 1, 0, 0 },
    { 0, 1, 1, 0 },
    { 0, 0, 0, 1 },
    { 1, 0, 1, 0 }
  };
  printResult(ex2, expected2, flipAndInvertImage(ex2));

  return 0;
}
