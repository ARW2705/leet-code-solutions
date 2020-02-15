#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

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


std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
  std::vector<std::pair<int, int>> graded;
  for (size_t row=0; row < mat.size(); ++row) {
    graded.push_back(std::make_pair(std::accumulate(mat[row].begin(), mat[row].end(), 0), row));
  }
  std::stable_sort(
    graded.begin(),
    graded.end(),
    [](const std::pair<int, int> lhs, const std::pair<int, int> rhs) {
      return lhs.first < rhs.first;
    }
  );

  std::vector<int> weakest;
  weakest.reserve(k);
  for (int i=0; i < k; ++i) {
    weakest.push_back(graded[i].second);
  }
  return weakest;
}

int main() {
  std::vector<std::vector<int>> m1 {
    { 1, 1, 0, 0, 0 },
    { 1, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0 },
    { 1, 1, 1, 1, 1 }
  };
  std::vector<int> weakestRows1 = kWeakestRows(m1, 3);
  std::vector<int> expected1 = { 2, 0, 3 };
  printVector(weakestRows1);
  std::cout << (compareVector(expected1, weakestRows1) ? "PASS": "FAIL") << "\n";

  std::vector<std::vector<int>> m2 {
    { 1, 0, 0, 0 },
    { 1, 1, 1, 1 },
    { 1, 0, 0, 0 },
    { 1, 0, 0, 0 }
  };
  std::vector<int> weakestRows2 = kWeakestRows(m2, 2);
  std::vector<int> expected2 = { 0, 2 };
  printVector(weakestRows2);
  std::cout << (compareVector(expected2, weakestRows2) ? "PASS": "FAIL") << "\n";

  std::vector<std::vector<int>> m3 {
    { 1, 0 },
    { 1, 0 },
    { 1, 0 },
    { 1, 1 }
  };
  std::vector<int> weakestRows3 = kWeakestRows(m3, 4);
  std::vector<int> expected3 = { 0, 1, 2, 3 };
  printVector(weakestRows3);
  std::cout << (compareVector(expected3, weakestRows3) ? "PASS": "FAIL") << "\n";

  std::vector<std::vector<int>> m4 {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
    { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 }
  };
  std::vector<int> weakestRows4 = kWeakestRows(m4, 7);
  std::vector<int> expected4 = { 17, 21, 3, 7, 12, 25, 1 };
  printVector(weakestRows4);
  std::cout << (compareVector(expected4, weakestRows4) ? "PASS": "FAIL") << "\n";

  return 0;
}
