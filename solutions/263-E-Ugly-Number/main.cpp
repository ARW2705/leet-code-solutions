#include <iostream>
#include <cmath>
#include "../../utilities/print-success.cpp"

bool isUgly(int n) {
  if (n == 1) return true;
  if (n < 0) return false;
  bool hasUglyFactor = false;
  int factor = 2;
  int limit = std::ceil(std::sqrt(n));
  while (n > 1) {
    while (n >= factor) {
      if (factor > 5 && n > limit) return false;
      if (n % factor == 0) {
        if (factor == 2 || factor == 3 || factor == 5) {
          hasUglyFactor = true;
        } else {
          return false;
        }
        n /= factor;
      } else {
        factor += (factor == 2) ? 1 : 2;
      }
    }
  }
  return hasUglyFactor;
}

int main() {
  printSuccess(isUgly(6));
  printSuccess(!isUgly(14));
  printSuccess(!isUgly(1332185066));
  printSuccess(!isUgly(583474588));
  printSuccess(!isUgly(-2147483648));
  return 0;
}
