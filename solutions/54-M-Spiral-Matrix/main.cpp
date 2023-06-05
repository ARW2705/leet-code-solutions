#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"
#include "../../utilities/compare-vectors.cpp"

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;
  int overallSize = matrix.size() * matrix[0].size();
  int leftBound = -1, rightBound = matrix[0].size(), upperBound = 0, lowerBound = matrix.size();
  int row = 0, col = 0;
  enum Direction { right, down, left, up };
  Direction direction = right;
  while (result.size() < overallSize) {
    switch (direction) {
      case right:
        if (col == rightBound) {
          --col;
          ++row;
          --rightBound;
          direction = down;
        } else {
          result.push_back(matrix[row][col]);
          ++col;
        }
        break;
      case down:
        if (row == lowerBound) {
          --row;
          --col;
          --lowerBound;
          direction = left;
        } else {
          result.push_back(matrix[row][col]);
          ++row;
        }
        break;
      case left:
        if (col == leftBound) {
          ++col;
          --row;
          ++leftBound;
          direction = up;
        } else {
          result.push_back(matrix[row][col]);
          --col;
        }
        break;
      case up:
        if (row == upperBound) {
          ++row;
          ++col;
          ++upperBound;
          direction = right;
        } else {
          result.push_back(matrix[row][col]);
          --row;
        }
        break;
      default:
        break;
    }
  }

  return result;
}

int main() {
  vector<vector<int>> m1 {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };
  vector<int> e1 {1,2,3,6,9,8,7,4,5};
  vector<int> r1 = spiralOrder(m1);
  printVector(r1);
  printSuccess(compareVector(r1, e1));

  vector<vector<int>> m2 {
    { 1, 2,  3,  4  },
    { 5, 6,  7,  8  },
    { 9, 10, 11, 12 }
  };
  vector<int> e2 {1,2,3,4,8,12,11,10,9,5,6,7};
  vector<int> r2 = spiralOrder(m2);
  printVector(r2);
  printSuccess(compareVector(r2, e2));

  vector<vector<int>> m3 { { 1 } };
  vector<int> e3 { 1 };
  vector<int> r3 = spiralOrder(m3);
  printVector(r3);
  printSuccess(compareVector(r3, e3));

  vector<vector<int>> m4 {
    { 1,  2,  3,  4  },
    { 5,  6,  7,  8  },
    { 9,  10, 11, 12 },
    { 13, 14, 15, 16 }
  };
  vector<int> e4 {1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10 };
  vector<int> r4 = spiralOrder(m4);
  printVector(r4);
  printSuccess(compareVector(r4, e4));

  return 0;
}
