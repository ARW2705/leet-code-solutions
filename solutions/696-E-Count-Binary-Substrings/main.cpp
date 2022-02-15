#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

int countBinarySubstrings(std::string s) {
  int count = 0;
  char currentBit = s[0];
  int leftWall, rightWall;
  int size = s.size();
  for (int i = 1; i < size; ++i) {
    if (s[i] != currentBit) {
      leftWall = i - 1;
      rightWall = i;
      while (leftWall >= 0 && rightWall < size && s[leftWall] == currentBit && s[leftWall] != s[rightWall]) {
        ++count;
        --leftWall;
        ++rightWall;
      }
      currentBit = s[i];
    }
  }

  return count;
}

int main() {
  std::string s1 = "00110011";
  printSuccess(countBinarySubstrings(s1) == 6);

  std::string s2 = "10101";
  printSuccess(countBinarySubstrings(s2) == 4);
  return 0;
}
