#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"

// bool checkMerged(std::vector<int>& merged, std::vector<int>& expected) {
//   for (size_t i = 0; i < merged.size(); ++i) {
//     if (merged[i] != expected[i]) {
//       return false;
//     }
//   }
//   return true;
// }

// std::string stringify(std::vector<int>& v) {
//   std::string result = "[ ";
//   for (size_t i = 0; i < v.size(); ++i) {
//     result.append(std::to_string(v[i]));
//     if (i < v.size() - 1) {
//       result.append(", ");
//     }
//   }
//   result.append(" ]");
//   return result;
// }

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  int j = m - 1, k = n - 1;
  for (int i = m + n - 1; i >= 0; --i) {
    if (m == 0 || j < 0) {
      nums1[i] = nums2[k];
      --k;
    } else if (n == 0 || k < 0) {
      break;
    } else if (nums1[j] > nums2[k]) {
      nums1[i] = nums1[j];
      --j;
    } else {
      nums1[i] = nums2[k];
      --k;
    }
  }
}

int main() {
  std::vector<int> test1a { 1, 2, 3, 0, 0, 0 };
  std::vector<int> test1b { 2, 5, 6 };
  std::vector<int> expected1 { 1, 2, 2, 3, 5, 6 };
  merge(test1a, 3, test1b, 3);
  printSuccess(compareVector(test1a, expected1));

  std::vector<int> test2a { 1 };
  std::vector<int> test2b;
  std::vector<int> expected2 { 1 };
  merge(test2a, 1, test2b, 0);
  printSuccess(compareVector(test2a, expected2));

  std::vector<int> test3a { 0 };
  std::vector<int> test3b { 1 };
  std::vector<int> expected3 { 1 };
  merge(test3a, 0, test3b, 1);
  printSuccess(compareVector(test3a, expected3));

  std::vector<int> test4a { 2, 0 };
  std::vector<int> test4b { 1 };
  std::vector<int> expected4 { 1, 2 };
  merge(test4a, 1, test4b, 1);
  printSuccess(compareVector(test4a, expected4));

  std::vector<int> test5a { 4, 0, 0, 0, 0, 0 };
  std::vector<int> test5b { 1, 2, 3, 5, 6 };
  std::vector<int> expected5 { 1, 2, 3, 4, 5, 6 };
  merge(test5a, 1, test5b, 5);
  printSuccess(compareVector(test5a, expected5));

  std::vector<int> test6a { 1, 2, 4, 5, 6, 0 };
  std::vector<int> test6b { 3 };
  std::vector<int> expected6 { 1, 2, 3, 4, 5, 6 };
  merge(test6a, 5, test6b, 1);
  printSuccess(compareVector(test6a, expected6));

  std::vector<int> test7a { 0, 0, 3, 0, 0, 0, 0, 0, 0 };
  std::vector<int> test7b { -1, 1, 1, 1, 2, 3 };
  std::vector<int> expected7 { -1, 0, 0, 1, 1, 1, 2, 3, 3 };
  merge(test7a, 3, test7b, 6);
  printSuccess(compareVector(test7a, expected7));

  return 0;
}
