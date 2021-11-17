#include <iostream>
#include <vector>
#include "../../utilities/print-vector.cpp"
#include "../../utilities/print-success.cpp"

bool compareVectors(std::vector<int>& v1, std::vector<int>& v2, int compareLength) {
  if (v1.size() < compareLength || v2.size() < compareLength) return false;
  for (int i = 0; i < compareLength; ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

int removeDuplicates(std::vector<int>& nums) {
  if (!nums.size()) return 0;
  int placeIndex = 1;
  int current = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] != current) {
      current = nums[i];
      std::swap(nums[i], nums[placeIndex]);
      ++placeIndex;
    }
  }
  return placeIndex;
}

int main() {
  std::vector<int> v1 { 1, 1, 2 };
  std::vector<int> e1 { 1, 2 };
  int r1 = removeDuplicates(v1);
  std::cout << "r1 = " << r1 << "\n";
  printSuccess(compareVectors(v1, e1, r1));
  printVector(v1);

  std::vector<int> v2 { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
  std::vector<int> e2 { 0, 1, 2, 3, 4 };
  int r2 = removeDuplicates(v2);
  std::cout << "r2 = " << r2 << "\n";
  printSuccess(compareVectors(v2, e2, r2));
  printVector(v2);

  std::vector<int> v3 {};
  std::vector<int> e3 {};
  int r3 = removeDuplicates(v3);
  std::cout << "r3 = " << r3 << "\n";
  printSuccess(compareVectors(v3, e3, r3));
  printVector(v3);

  std::vector<int> v4 { 1, 1 };
  std::vector<int> e4 { 1 };
  int r4 = removeDuplicates(v4);
  std::cout << "r4 = " << r4 << "\n";
  printSuccess(compareVectors(v4, e4, r4));
  printVector(v4);
  return 0;
}
