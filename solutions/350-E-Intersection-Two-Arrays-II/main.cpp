#include <iostream>
#include <vector>
#include <map>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

void mapVector(std::map<int, int>& m, std::vector<int>& v) {
  for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
    ++m[*iter];
  }
}

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
  std::map<int, int> numsMap1;
  mapVector(numsMap1, nums1);
  std::map<int, int> numsMap2;
  mapVector(numsMap2, nums2);
  std::map<int, int>& largerMap = numsMap1.size() >= numsMap2.size() ? numsMap1 : numsMap2;
  std::map<int, int>& smallerMap = numsMap1.size() < numsMap2.size() ? numsMap1 : numsMap2;
  std::vector<int> result;
  for (std::map<int, int>::iterator iter = smallerMap.begin(); iter != smallerMap.end(); ++iter) {
    if (largerMap.find(iter->first) != largerMap.end()) {
      result.insert(result.end(), std::min(largerMap[iter->first], iter->second), iter->first);
    }
  }
  return result;
}

int main() {
  std::vector<int> test1a { 1, 2, 2, 1 };
  std::vector<int> test1b { 2, 2 };
  std::vector<int> expected1 { 2, 2 };
  std::vector<int> result1 = intersect(test1a, test1b);
  printVector(result1);
  std::cout << (compareVector(result1, expected1) ? "PASS": "FAIL");
  std::cout << "\n";

  std::vector<int> test2a { 4, 9, 5 };
  std::vector<int> test2b { 9, 4, 9, 8, 4 };
  std::vector<int> expected2a { 4, 9 };
  std::vector<int> expected2b { 9, 4 };
  std::vector<int> result2 = intersect(test2a, test2b);
  printVector(result2);
  std::cout << ((compareVector(result2, expected2a) || compareVector(result2, expected2b)) ? "PASS": "FAIL") << std::endl;
  return 0;
}
