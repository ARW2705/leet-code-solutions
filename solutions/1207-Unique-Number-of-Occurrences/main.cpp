#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool uniqueOccurrencesUsingBuckets(std::vector<int>& arr) {
  std::sort(arr.begin(), arr.end());
  std::vector<int> occurrences(arr.size() > arr[arr.size() - 1] ? arr.size(): arr[arr.size() - 1], 0);

  int elemStreakStart = 0;
  for (int i=0; i < arr.size(); ++i) {
    if (i == arr.size() - 1 || arr[i] != arr[i + 1]) {
      if (occurrences[i - elemStreakStart + 1] == 0) {
        occurrences[i - elemStreakStart + 1] = arr[i];
        elemStreakStart = i + 1;
      } else {
        return false;
      }
    }
  }
  return true;
}

bool uniqueOccurrences(std::vector<int>& arr) {
  std::unordered_map<int, int> elemCounts;
  for (int i : arr) {
    ++elemCounts[i];
  }
  std::unordered_map<int, int>::const_iterator outerIter;
  std::unordered_map<int, int>::const_iterator innerIter;
  for (outerIter = elemCounts.begin(); outerIter != elemCounts.end(); ++outerIter) {
    for (innerIter = elemCounts.begin(); innerIter != elemCounts.end(); ++innerIter) {
      if (outerIter != innerIter && outerIter->second == innerIter->second) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  std::vector<int> test1 { 1, 2, 2, 1, 1, 3 };
  std::cout << (uniqueOccurrences(test1) ? "PASS": "FAIL") << "\n";

  std::vector<int> test2 { 1, 2 };
  std::cout << (uniqueOccurrences(test2) ? "FAIL": "PASS") << "\n";

  std::vector<int> test3 { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };
  std::cout << (uniqueOccurrences(test3) ? "PASS": "FAIL") << "\n";
  return 0;
}
