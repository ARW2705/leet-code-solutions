#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../utilities/print-success.cpp"

bool divideArray(std::vector<int>& nums) {
  std::unordered_set<int> encountered;
  for (int num : nums) {
    if (encountered.find(num) == encountered.end()) {
      encountered.insert(num);
    } else {
      encountered.erase(num);
    }
  }

  return encountered.size() == 0;
}

int main() {
  std::vector<int> v1 { 3, 2, 3, 2, 2, 2 };
  printSuccess(divideArray(v1));

  std::vector<int> v2 { 1, 2, 3, 4 };
  printSuccess(!divideArray(v2));

  return 0;
}
