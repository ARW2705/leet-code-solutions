#include <vector>
#include <iostream>

int searchHelper(std::vector<int>& nums, int target, int startIndex, int stopIndex) {
  if (stopIndex == startIndex && nums[startIndex] != target) {
    return -1;
  }
  int mid = (startIndex + stopIndex) / 2;
  if (target > nums[mid]) {
    return searchHelper(nums, target, mid + 1, stopIndex);
  } else if (target < nums[mid]) {
    return searchHelper(nums, target, startIndex, mid);
  } else {
    return mid;
  }
}

int search(std::vector<int>& nums, int target) {
  return searchHelper(nums, target, 0, nums.size() - 1);
}

int searchIter(std::vector<int>& nums, int target) {
  int leftIndex = 0, rightIndex = nums.size() - 1, mid;
  while (leftIndex <= rightIndex) {
    mid = (leftIndex + rightIndex) / 2;
    if (target > nums[mid]) {
      leftIndex = mid + 1;
    } else if (target < nums[mid]) {
      rightIndex = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  std::vector<int> test1 {-1,0,3,5,9,12};
  int target1 = 9;
  int expected1 = 4;
  std::cout << (searchIter(test1, target1) == expected1 ? "PASS" : "FAIL") << "\n";

  std::vector<int> test2 {-1,0,3,5,9,12};
  int target2 = 2;
  int expected2 = -1;
  std::cout << (searchIter(test2, target2) == expected2 ? "PASS" : "FAIL") << "\n";

  std::vector<int> test3 {5};
  int target3 = 5;
  int expected3 = 0;
  std::cout << (searchIter(test3, target3) == expected3 ? "PASS" : "FAIL") << "\n";

  std::cout << std::endl;

  return 0;
}
