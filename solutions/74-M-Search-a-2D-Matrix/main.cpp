#include <iostream>
#include <vector>

// bool binarySearch(std::vector<int>& v, int target, int startIndex, int endIndex) {
//   if (endIndex < startIndex) {
//     return false;
//   } else {
//     int mid = startIndex + ((endIndex - startIndex) / 2);
//     if (target < v[mid]) {
//       return binarySearch(v, target, startIndex, mid - 1);
//     } else if (target > v[mid]) {
//       return binarySearch(v, target, mid + 1, endIndex);
//     } else {
//       return true;
//     }
//   }
// }

bool binarySearch(std::vector<int>& v, int target) {
  int leftIndex = 0, rightIndex = v.size() - 1, mid;
  while (leftIndex <= rightIndex) {
    mid = leftIndex + ((rightIndex - leftIndex) / 2);
    if (target < v[mid]) {
      rightIndex = mid - 1;
    } else if (target > v[mid]) {
      leftIndex = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  int min, max;
  for (int row = 0; row < matrix.size(); ++row) {
    min = matrix[row][0];
    max = matrix[row][matrix[row].size() - 1];
    if (target >= min && target <= max) {
      return binarySearch(matrix[row], target);
    }
  }
  return false;
}

int main() {
  std::vector<std::vector<int>> m1 {
    { 1 , 3 , 5 , 7  },
    { 10, 11, 16, 20 },
    { 23, 30, 34, 60 }
  };
  std::cout << (searchMatrix(m1, 3) ? "PASS" : "FAIL") << "\n";
  std::cout << (!searchMatrix(m1, 13) ? "PASS" : "FAIL") << "\n";

  std::vector<std::vector<int>> m2 { { 1 } };
  std::cout << (searchMatrix(m2, 1) ? "PASS" : "FAIL") << "\n";
  return 0;
}
