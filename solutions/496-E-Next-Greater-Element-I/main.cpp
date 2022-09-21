#include <iostream>
#include <vector>
#include <map>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
  std::map<int, int> dict;

  for (int i = 0; i < nums2.size(); ++i) {
    int next = -1;
    for (int j = i + 1; j < nums2.size(); ++j) {
      if (nums2[j] > nums2[i]) {
        next = nums2[j];
        break;
      }
    }
    dict[nums2[i]] = next;
  }

  std::vector<int> results;
  for (int i = 0; i < nums1.size(); ++i) {
    results.push_back(dict[nums1[i]]);  
  }

  return results;
}

int main() {
  std::vector<int> v1a { 4, 1, 2 };
  std::vector<int> v1b { 1, 3, 4, 2 };
  std::vector<int> r1 = nextGreaterElement(v1a, v1b);
  std::vector<int> e1 { -1, 3, -1 };
  printSuccess(compareVector(r1, e1));

  std::vector<int> v2a { 2, 4 };
  std::vector<int> v2b { 1, 2, 3, 4 };
  std::vector<int> r2 = nextGreaterElement(v2a, v2b);
  std::vector<int> e2 { 3, -1 };
  printSuccess(compareVector(r2, e2));

  return 0;
}
