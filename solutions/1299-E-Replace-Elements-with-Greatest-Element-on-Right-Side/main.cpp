#include <iostream>
#include <vector>

bool compareVectors(std::vector<int>& v1, std::vector<int>& v2) {
  if (v1.size() != v2.size()) return false;
  for (size_t i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

void printVector(std::vector<int>& v) {
  std::cout << "[";
  for (size_t i=0; i < v.size(); ++i) {
    std::cout << v[i];
    if (i < v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

std::vector<int> replaceElements(std::vector<int>& arr) {
  std::vector<int> result(arr.size());
  int nextMaxIndex = 0;
  for (int i=0; i < arr.size() - 1; ++i) {
    if (i >= nextMaxIndex) {
      nextMaxIndex += 1;
      for (int j=i+1; j < arr.size(); ++j) {
        if (arr[j] > arr[nextMaxIndex]) {
          nextMaxIndex = j;
        }
      }
    }
    result[i] = arr[nextMaxIndex];
  }
  result[result.size() - 1] = -1;
  return result;
}

int main() {
  std::vector<int> test1 { 17, 18, 5, 4, 6, 1 };
  std::vector<int> expected1 { 18, 6, 6, 6, 1, -1 };
  std::vector<int> result1 = replaceElements(test1);
  printVector(result1);
  std::cout << (compareVectors(expected1, result1) ? "PASS": "FAIL") << "\n";

  std::vector<int> test2 { 56903,18666,60499,57517,26961 };
  std::vector<int> expected2 { 60499,60499,57517,26961,-1 };
  std::vector<int> result2 = replaceElements(test2);
  printVector(result2);
  std::cout << (compareVectors(expected2, result2) ? "PASS": "FAIL") << std::endl;

  return 0;
}
