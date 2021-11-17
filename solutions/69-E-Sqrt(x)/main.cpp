#include <iostream>
#include "../../utilities/print-success.cpp"

// int mySqrt(int x) {
//   long long root = 1;
//   while (root * root <= x) {
//     ++root;
//   }
//   return static_cast<int>(root - 1);
// }

int mySqrt(int x, int floor, int ceiling) {
  int half = (ceiling + floor) / 2;
  long long halfSquared = static_cast<long long>(half) * static_cast<long long>(half);
  if (halfSquared == x) {
    return half;
  } else if (floor == ceiling) {
    return floor - 1;
  } else if (halfSquared > x) {
    return mySqrt(x, floor, half);
  } else {
    return mySqrt(x, half + 1, ceiling);
  }
}

int mySqrt(int x) {
  return mySqrt(x, 0, x);
}

int main() {
  printSuccess(mySqrt(4) == 2);
  printSuccess(mySqrt(8) == 2);
  printSuccess(mySqrt(10001) == 100);
  printSuccess(mySqrt(1) == 1);
  return 0;
}
