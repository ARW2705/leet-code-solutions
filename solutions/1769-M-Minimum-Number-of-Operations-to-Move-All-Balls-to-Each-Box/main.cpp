#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

using namespace std;

// brute force
// vector<int> minOperations(string boxes) {
//   vector<int> answer(boxes.size());
//   int dist = 0;
//   for (int i = 0; i < boxes.size(); ++i) {
//     for (int j = 0; j < boxes.size(); ++j) {
//       if (boxes[j] == '1') {
//         dist += abs(i - j);
//       }
//     }
//     answer[i] = dist;
//     dist = 0;
//   }

//   return answer;
// }

// ltr / rtl
vector<int> minOperations(string boxes) {
  int size = boxes.size();

  int toLeftCount, toLeftCountPrevious = 0;
  int toRightCount, toRightCountPrevious = 0;
  vector<int> toLeftMoves(size, 0);
  vector<int> toRightMoves(size, 0);
  for (int i = 1; i < size; ++i) {
    toRightCount = toRightCountPrevious + boxes[i - 1] - '0';
    toRightMoves[i] = toRightMoves[i - 1] + toRightCount;
    toRightCountPrevious = toRightCount;

    toLeftCount = toLeftCountPrevious + boxes[size - i] - '0';
    toLeftMoves[size - i - 1] = toLeftMoves[size - i] + toLeftCount;
    toLeftCountPrevious = toLeftCount;
  }
  
  vector<int> answer(size);
  for (int i = 0; i < size; ++i) {
    answer[i] = toRightMoves[i] + toLeftMoves[i];
  }

  return answer;
}

int main() {
  string b1 = "110";
  vector<int> e1 { 1, 1, 3 };
  vector<int> r1 = minOperations(b1);
  printSuccess(compareVector(r1, e1));

  string b2 = "001011";
  vector<int> e2 { 11, 8, 5, 4, 3, 4 };
  vector<int> r2 = minOperations(b2);
  printSuccess(compareVector(r2, e2));
  
  return 0;
}
