#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums) {
  int maxSum = nums.at(0);
  int currentSum = nums.at(0);
  int next = 0;
  for (std::vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); ++iter) {
    next = *iter + currentSum;
    if (*iter > next) {
      currentSum = *iter;
    } else {
      currentSum = next;
    }
    if (currentSum > maxSum) {
      maxSum = currentSum;
    }
  }
  return maxSum;
}

int main() {
  std::vector<int> test1 { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  std::vector<int> test2 { 1 };
  std::vector<int> test3 { 5, 4, -1, 7, 8 };
  std::vector<int> test4 { 1, 2 };
  std::vector<int> test5 { -1, -2 };

  const int result1 = maxSubArray(test1);
  std::cout << "For array [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ]: " << result1 << "\n";
  const int result2 = maxSubArray(test2);
  std::cout << "For array [ 1 ]: " << result2 << "\n";
  const int result3 = maxSubArray(test3);
  std::cout << "For array [ 5, 4, -1, 7, 8 ]: " << result3 << "\n";
  const int result4 = maxSubArray(test4);
  std::cout << "For array [ 1, 2 ]: " << result4 << "\n";
  const int result5 = maxSubArray(test5);
  std::cout << "For array [ -1, -2 ]: " << result5 << "\n";
  std::cout << (result1 == 6 && result2 == 1 && result3 == 23 && result4 == 3 && result5 == -1 ? "PASS" : "FAIL") << std::endl;
  return 0;
}
