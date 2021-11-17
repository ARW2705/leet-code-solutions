#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

int strStr(std::string haystack, std::string needle) {
  int windowSize = needle.size();
  int searchSize = haystack.size() - windowSize + 1;
  if (!windowSize) return 0;
  for (int i = 0; i < searchSize; ++i) {
    if (haystack.compare(i, windowSize, needle) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::string h1 = "hello";
  std::string n1 = "ll";
  printSuccess(strStr(h1, n1) == 2);

  std::string h2 = "aaaaa";
  std::string n2 = "bba";
  printSuccess(strStr(h2, n2) == -1);

  std::string h3 = "";
  std::string n3 = "";
  printSuccess(strStr(h3, n3) == 0);

  std::string h4 = "";
  std::string n4 = "a";
  printSuccess(strStr(h4, n4) == -1);

  std::string h5 = "a";
  std::string n5 = "a";
  printSuccess(strStr(h5, n5) == 0);

  return 0;
}
