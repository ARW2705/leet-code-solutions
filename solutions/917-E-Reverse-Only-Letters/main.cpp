#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string reverseOnlyLetters(std::string s) {
  int leftIndex = 0;
  int rightIndex = s.size() - 1;

  while (leftIndex < rightIndex) {
    if (std::isalpha(s[leftIndex]) && std::isalpha(s[rightIndex])) {
      std::swap(s[leftIndex], s[rightIndex]);
      ++leftIndex;
      --rightIndex;
    } else if (std::isalpha(s[leftIndex])) {
      --rightIndex;
    } else {
      ++leftIndex;
    }
  }

  return s;
}

int main() {
  std::string s1 = "ab-cd";
  printSuccess(reverseOnlyLetters(s1).compare("dc-ba") == 0);

  std::string s2 = "a-bC-dEf-ghIj";
  printSuccess(reverseOnlyLetters(s2).compare("j-Ih-gfE-dCba") == 0);

  std::string s3 = "Test1ng-Leet=code-Q!";
  printSuccess(reverseOnlyLetters(s3).compare("Qedo1ct-eeLg=ntse-T!") == 0);

  std::string s4 = "a";
  printSuccess(reverseOnlyLetters(s4).compare("a") == 0);

  return 0;
}
