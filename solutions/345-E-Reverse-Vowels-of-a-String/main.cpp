#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

bool isVowel(char c) {
  char vowels[10] { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
  for (char vowel : vowels) {
    if (vowel == c) {
      return true;
    }
  }
  return false;
}

std::string reverseVowels(std::string s) {
  int leftIndex = 0;
  int rightIndex = s.size() - 1;
  bool isLeftVowel, isRightVowel;
  while (leftIndex < rightIndex) {
    isLeftVowel = isVowel(s[leftIndex]);
    isRightVowel = isVowel(s[rightIndex]);
    if (isLeftVowel && isRightVowel) {
      std::swap(s[leftIndex++], s[rightIndex--]);
    } else if (isLeftVowel) {
      rightIndex--;
    } else {
      leftIndex++;
    }
  }
  return s;
}

int main() {
  std::string s1 = "hello";
  std::string r1 = reverseVowels(s1);
  printSuccess(r1.compare("holle") == 0);
  std::cout << r1 << "\n";

  std::string s2 = "leetcode";
  std::string r2 = reverseVowels(s2);
  printSuccess(r2.compare("leotcede") == 0);
  std::cout << r2 << "\n";

  return 0;
}
