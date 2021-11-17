#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

std::vector<std::string> summaryRanges(std::vector<int>& nums) {
  std::vector<std::string> ranges;
  if (!nums.size()) {
    return ranges;
  }

  int startIndex = 0;
  std::string range;
  for (int i = 0; i < nums.size(); ++i) {
    if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) {
      if (startIndex == i) {
        range = std::to_string(nums[i]);
      } else {
        range = std::to_string(nums[startIndex]) + "->" + std::to_string(nums[i]);
      }
      ranges.push_back(range);
      startIndex = i + 1;
    }
  }

  return ranges;
}

int main() {
  std::vector<int> v1 { 0, 1, 2, 4, 5, 7 };
  std::vector<std::string> r1 = summaryRanges(v1);
  printSuccess(r1[0].compare("0->2") == 0);
  printSuccess(r1[1].compare("4->5") == 0);
  printSuccess(r1[2].compare("7") == 0);
  std::cout << "\n";

  std::vector<int> v2 { 0, 2, 3, 4, 6, 8, 9 };
  std::vector<std::string> r2 = summaryRanges(v2);
  printSuccess(r2[0].compare("0") == 0);
  printSuccess(r2[1].compare("2->4") == 0);
  printSuccess(r2[2].compare("6") == 0);
  printSuccess(r2[3].compare("8->9") == 0);
  std::cout << "\n";

  std::vector<int> v3;
  std::vector<std::string> r3 = summaryRanges(v3);
  printSuccess(r3.size() == 0);
  std::cout << "\n";

  std::vector<int> v4 { -1 };
  std::vector<std::string> r4 = summaryRanges(v4);
  printSuccess(r4[0].compare("-1") == 0);
  std::cout << "\n";

  std::vector<int> v5 { 0 };
  std::vector<std::string> r5 = summaryRanges(v5);
  printSuccess(r5[0].compare("0") == 0);
  std::cout << "\n";

  return 0;
}
