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

int findLastValidValue(std::vector<int>& nums, int val, int start) {
  for (int i = start; i >= 0; --i) {
    if (nums[i] != val) {
      return i;
    }
  }
  return -1;
}

int removeElement(std::vector<int>& nums, int val) {
  if (!nums.size()) return 0;
  int sourceIndex = findLastValidValue(nums, val, nums.size() - 1);
  for (int i = 0; i < nums.size(); ++i) {
    if (sourceIndex > i && nums[i] == val) {
      std::swap(nums[i], nums[sourceIndex]);
      sourceIndex = findLastValidValue(nums, val, sourceIndex - 1);
    }
  }
  return sourceIndex + 1;
}

int main() {
  std::vector<int> v1 { 3, 2, 2, 3 };
  std::vector<int> e1 { 2, 2 };
  int r1 = removeElement(v1, 3);
  std::cout << "r1 = " << r1 << "\n";
  printSuccess(compareVectors(v1, e1, r1));
  printVector(v1);

  std::vector<int> v2 { 0, 1, 2, 2, 3, 0, 2, 4, 2 };
  std::vector<int> e2 { 0, 1, 4, 0, 3 };
  int r2 = removeElement(v2, 2);
  std::cout << "r2 = " << r2 << "\n";
  printSuccess(compareVectors(v2, e2, r2));
  printVector(v2);

  std::vector<int> v3 { 1, 1, 1 };
  std::vector<int> e3 { };
  int r3 = removeElement(v3, 1);
  std::cout << "r3 = " << r3 << "\n";
  printSuccess(compareVectors(v3, e3, r3));
  printVector(v3);

  return 0;
}
