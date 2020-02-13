#include <iostream>
#include <vector>
#include <unordered_map>

int repeatedNTimes(std::vector<int>& A) {
  std::unordered_map<int, int> previousValues;
  int nElems = A.size() / 2;
  for (int num : A) {
    if (++previousValues[num] == nElems) {
      return num;
    }
  }
}

int main() {
  std::vector<int> test1 { 1, 2, 3, 3 };
  int result1 = repeatedNTimes(test1);
  std::cout << "Test 1: " << (result1 == 3 ? "PASS": "FAIL") << "; " << result1 << "\n";

  std::vector<int> test2 { 2, 1, 2, 5, 3, 2 };
  int result2 = repeatedNTimes(test2);
  std::cout << "Test 1: " << (result2 == 2 ? "PASS": "FAIL") << "; " << result2 << "\n";

  std::vector<int> test3 { 5, 1, 5, 2, 5, 3, 5, 4 };
  int result3 = repeatedNTimes(test3);
  std::cout << "Test 1: " << (result3 == 5 ? "PASS": "FAIL") << "; " << result3 << "\n";

  return 0;
}
