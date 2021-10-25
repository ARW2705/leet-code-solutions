#include <iostream>

bool isBadVersion(int version) {
  return version >= 4;
}

int firstBadVersion(int n) {
  int leftBound = 0, rightBound = n, tryVersion;
  while ((rightBound - leftBound) > 1) {
    tryVersion = (rightBound - leftBound) / 2 + leftBound;
    if (isBadVersion(tryVersion)) {
      rightBound = tryVersion;
    } else {
      leftBound = tryVersion;
    }
  }
  return rightBound;
}

int main() {
  std::cout << (firstBadVersion(10) == 4 ? "PASS" : "FAIL") << "\n";
  std::cout << std::endl;
  return 0;
}
