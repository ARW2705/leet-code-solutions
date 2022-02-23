#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"

std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
  std::vector<int> target;
  for (int i = 0; i < nums.size(); ++i) {
    target.insert(target.begin() + index[i], nums[i]);
  }
  return target;
}

int main() {
  std::vector<int> n1 { 0, 1, 2, 3, 4 };
  std::vector<int> i1 { 0, 1, 2, 2, 1 };
  std::vector<int> e1 { 0, 4, 1, 3, 2 };
  std::vector<int> r1 = createTargetArray(n1, i1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> n2 { 1, 2, 3, 4, 0 };
  std::vector<int> i2 { 0, 1, 2, 3, 0 };
  std::vector<int> e2 { 0, 1, 2, 3, 4 };
  std::vector<int> r2 = createTargetArray(n2, i2);
  printSuccess(compareVector(e2, r2));

  std::vector<int> n3 { 1 };
  std::vector<int> i3 { 0 };
  std::vector<int> e3 { 1 };
  std::vector<int> r3 = createTargetArray(n3, i3);
  printSuccess(compareVector(e3, r3));

  return 0;
}
