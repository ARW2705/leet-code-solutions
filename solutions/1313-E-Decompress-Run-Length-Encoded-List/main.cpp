#include <vector>
#include <iostream>

bool compareVectors(std::vector<int>& v1, std::vector<int>& v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  for (int i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

std::vector<int> decompress(std::vector<int>& nums) {
  std::vector<int> result;
  for (int i=0; i < nums.size(); i += 2) {
    result.insert(result.end(), nums[i], nums[i + 1]);
  }
  return result;
}

int main() {
  std::vector<int> nums1 { 1, 2, 3, 4 };
  std::vector<int> nums2 { 2, 3, 4, 2, 1, 5, 3, 7 };

  std::vector<int> expected1 { 2, 4, 4, 4 };
  std::vector<int> expected2 { 3, 3, 2, 2, 2, 2, 5, 7, 7, 7 };

  std::vector<int> result1 = decompress(nums1);
  std::vector<int> result2 = decompress(nums2);

  std::cout << "Test 1: " << (compareVectors(result1, expected1) ? "PASS": "FAIL") << "\n";
  std::cout << "Test 2: " << (compareVectors(result2, expected2) ? "PASS": "FAIL") << "\n";

  return 0;
}
