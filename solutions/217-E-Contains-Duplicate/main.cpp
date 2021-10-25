#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
  std::unordered_set<int> valueSet;
  for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
    std::unordered_set<int>::const_iterator found = valueSet.find(*iter);
    if (found == valueSet.end()) {
      valueSet.insert(*iter);
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<int> test1 { 1, 2, 3, 1 };
  std::vector<int> test2 { 1, 2, 3, 4 };
  std::vector<int> test3 { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

  const bool result1 = containsDuplicate(test1);
  std::cout << "For array [ 1, 2, 3, 1 ]: " << (result1 ? "TRUE" : "FALSE") << "\n";
  const bool result2 = containsDuplicate(test2);
  std::cout << "For array [ 1, 2, 3, 4 ]: " << (result2 ? "TRUE" : "FALSE") << "\n";
  const bool result3 = containsDuplicate(test3);
  std::cout << "For array [ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 ]: " << (result3 ? "TRUE" : "FALSE") << "\n";
  std::cout << (result1 && !result2 && result3 ? "PASS" : "FAIL") << std::endl;
  return 0;
}
