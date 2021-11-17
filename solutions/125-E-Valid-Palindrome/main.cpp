#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

bool isPalindrome(std::string s) {
  int leftIndex = 0;
  int rightIndex = s.size() - 1;
  bool isLeftComparable, isRightComparable;
  while (leftIndex <= rightIndex) {
    isLeftComparable = std::isalnum(s[leftIndex]);
    isRightComparable = std::isalnum(s[rightIndex]);
    if (isLeftComparable && isRightComparable) {
      if (std::tolower(s[leftIndex]) != std::tolower(s[rightIndex])) {
        return false;
      } else {
        ++leftIndex;
        --rightIndex;
      }
    } else if (isLeftComparable) {
      --rightIndex;
    } else {
      ++leftIndex;
    }
  }
  return true;
}

int main() {
  std::string s1 = "A man, a plan, a canal: Panama";
  printSuccess(isPalindrome(s1));

  std::string s2 = "race a car";
  printSuccess(!isPalindrome(s2));

  std::string s3 = " ";
  printSuccess(isPalindrome(s3));

  std::cout << std::endl;
}
