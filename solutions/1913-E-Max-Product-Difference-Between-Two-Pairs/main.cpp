#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int maxProductDifference(std::vector<int>& nums) {
  int max1 = 0, max2 = 0;
  int min1 = 10001, min2 = 10001;
  for (int num : nums) {
    if (num > max1) {
      max2 = max1;
      max1 = num;
    } else if (num > max2) {
      max2 = num;
    }

    if (num < min2) {
      min1 = min2;
      min2 = num;
    } else if (num < min1) {
      min1 = num;
    }
  }
  return (max1 * max2) - (min1 * min2);
}

int main() {
  std::vector<int> v1 { 5,6,2,7,4 };
  int r1 = maxProductDifference(v1);
  std::cout << r1 << "\n";
  printSuccess(r1 == 34);

  std::vector<int> v2 { 4,2,5,9,7,4,8 };
  int r2 = maxProductDifference(v2);
  std::cout << r2 << "\n";
  printSuccess(r2 == 64);

  std::vector<int> v3 { 5,9,4,6 };
  int r3 = maxProductDifference(v3);
  std::cout << r3 << "\n";
  printSuccess(r3 == 34);

  return 0;
}
