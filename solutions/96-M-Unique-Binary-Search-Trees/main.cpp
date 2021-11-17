#include <iostream>
#include <map>
#include <vector>
#include "../../utilities/print-matrix.cpp"
#include "../../utilities/print-success.cpp"

// int numTrees(int n) {
//   if (n <= 1) {
//     return 1;
//   }
//   int totalTrees = 0;
//   for (int i = 0; i < n; ++i) {
//     totalTrees += numTrees(i) * numTrees(n - i - 1);
//   }
//   return totalTrees;
// }

// int numTreesHelper(std::map<int, int>& cNums, int n) {
//   if (n <= 1) {
//     return 1;
//   }
//   int totalTrees = 0;
//   int leftOperand, rightOperand;
//   std::map<int, int>::iterator mapIter;
//   for (int i = 0; i < n; ++i) {
//     mapIter = cNums.find(i);
//     if (mapIter == cNums.end()) {
//       leftOperand = numTreesHelper(cNums, i);
//       cNums.insert(std::make_pair(i, leftOperand));
//     } else {
//       leftOperand = mapIter->second;
//     }
//
//     mapIter = cNums.find(n - i - 1);
//     if (mapIter == cNums.end()) {
//       rightOperand = numTreesHelper(cNums, n - i - 1);
//       cNums.insert(std::make_pair(n - i - 1, rightOperand));
//     } else {
//       rightOperand = mapIter->second;
//     }
//
//     totalTrees += leftOperand * rightOperand;
//   }
//   return totalTrees;
// }
//
// int numTrees(int n) {
//   std::map<int, int> cNums;
//   return numTreesHelper(cNums, n);
// }

int numTreesHelper(std::vector<int>& cNums, int n) {
  if (n <= 1) {
    return 1;
  }
  int totalTrees = 0;
  int leftOperand, rightOperand;
  for (int i = 0; i < n; ++i) {
    if (!cNums[i]) {
      leftOperand = numTreesHelper(cNums, i);
      cNums[i] = leftOperand;
    } else {
      leftOperand = cNums[i];
    }

    if (!cNums[n - i - 1]) {
      rightOperand = numTreesHelper(cNums, n - i - 1);
      cNums[n - i - 1] = rightOperand;
    } else {
      rightOperand = cNums[n - i - 1];
    }

    totalTrees += leftOperand * rightOperand;
  }
  return totalTrees;
}

int numTrees(int n) {
  std::vector<int> cNums(n, 0);
  return numTreesHelper(cNums, n);
}


int main() {
  printSuccess(numTrees(3) == 5);
  printSuccess(numTrees(1) == 1);
  for (int i = 1; i < 6; ++i) {
    std::cout << i << ": " << numTrees(i) << "\n";
  }
  return 0;
}
