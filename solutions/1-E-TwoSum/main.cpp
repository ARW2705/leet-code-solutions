#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::map<int, int> previousInts;
  std::map<int, int>::iterator mapIter;
  std::vector<int> results(2);
  int lookFor;
  int currentValue;
  for (int i = 0; i < nums.size(); ++i) {
    currentValue = nums.at(i);
    lookFor = target - currentValue;
    mapIter = previousInts.find(lookFor);
    if (mapIter == previousInts.end()) {
      previousInts.insert(std::pair<int, int>(currentValue, i));
    } else {
      results[0] = mapIter->second;
      results[1] = i;
      return results;
    }
  }
  return results;
}

bool hasPassed(std::vector<std::vector<int>>& results) {
  return (
    results[0][0] == 0
    && results [0][1] == 1
    && results[1][0] == 1
    && results[1][1] == 2
    && results[2][0] == 0
    && results[2][1] == 1
    && results[3][0] == 0
    && results[3][1] == 3
  );
}

int main() {
  std::vector<int> test1 { 2, 7, 11, 15 };
  std::vector<int> test2 { 3, 2, 4 };
  std::vector<int> test3 { 3, 3 };
  std::vector<int> test4 { 0, 4, 3, 0 };

  std::vector<int> result1 = twoSum(test1, 9);
  std::cout << "For vector [ 2, 7, 11, 15 ] and target 9: indicies [" << result1[0] << ", " << result1[1] << "]\n";
  std::vector<int> result2 = twoSum(test2, 6);
  std::cout << "For vector [ 3, 2, 4 ] and target 6: indicies [" << result2[0] << ", " << result2[1] << "]\n";
  std::vector<int> result3 = twoSum(test3, 6);
  std::cout << "For vector [ 3, 3 ] and target 6: indicies [" << result3[0] << ", " << result3[1] << "]\n";
  std::vector<int> result4 = twoSum(test4, 0);
  std::cout << "For vector [ 0, 4, 3, 0 ] and target 0: indicies [" << result4[0] << ", " << result4[1] << "]\n";
  std::vector<std::vector<int>> results { result1, result2, result3, result4 };
  std::cout << "Tests pass: " << (hasPassed(results) ? "PASS" : "FAIL") << std::endl;
  return 0;
}
