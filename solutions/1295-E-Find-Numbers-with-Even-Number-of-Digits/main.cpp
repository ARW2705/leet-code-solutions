#include <vector>
#include <iostream>
#include <cmath>

int findNumbers(std::vector<int>& nums) {
  int total = 0;
  for (int i=0; i < nums.size(); ++i) {
    total += static_cast<int>(std::log10(nums[i])) % 2 == 1;
  }
  return total;
}

int main() {
  std::vector<int> nums1 { 12, 345, 2, 6, 7896 };
  std::vector<int> nums2 { 555, 901, 482, 1771 };
  std::vector<int> nums3 { 437, 315, 322, 431, 686, 264, 442 };

  std::cout << findNumbers(nums1) << " even number of digits\n";
  std::cout << findNumbers(nums2) << " even number of digits\n";
  std::cout << findNumbers(nums3) << " even number of digits\n";

  return 0;
}
