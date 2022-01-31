#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
  std::vector<bool> encountered1(1000, false);
  for (int i = 0; i < nums1.size(); ++i) {
    encountered1[nums1[i]] = true;
  }
  std::vector<bool> encountered2(1000, false);
  for (int i = 0; i < nums2.size(); ++i) {
    encountered2[nums2[i]] = true;
  }
  std::vector<int> encountered;
  for (int i = 0; i < encountered1.size(); ++i) {
    if (encountered1[i] && encountered2[i]) {
      encountered.push_back(i);
    }
  }
  return encountered;
}

int main() {
  std::vector<int> v1a { 1, 2, 2, 1 };
  std::vector<int> v1b { 2, 2, };
  std::vector<int> e1 { 2 };
  std::vector<int> r1 = intersection(v1a, v1b);
  printVector(r1);
  printSuccess(compareVector(r1, e1));

  std::vector<int> v2a { 4, 9, 5 };
  std::vector<int> v2b { 9, 4, 9, 8, 4 };
  std::vector<int> e2 { 4, 9 };
  std::vector<int> r2 = intersection(v2a, v2b);
  printVector(r2);
  printSuccess(compareVector(r2, e2));

  std::vector<int> v3a { 3, 1, 2 };
  std::vector<int> v3b { 1 };
  std::vector<int> e3 { 1 };
  std::vector<int> r3 = intersection(v3a, v3b);
  printVector(r3);
  printSuccess(compareVector(r3, e3));

  return 0;
}
