#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

int lengthOfLastWord(std::string s) {
  int size = s.size();
  int endIndex = size - 1;
  for (int i = size - 1; i >= 0; --i) {
    if (s[i] == ' ' && i == endIndex) {
      --endIndex;
    } else if (s[i] == ' ') {
      return endIndex - i;
    }
  }
  return endIndex + 1;
}

int main() {
  std::string s1 = "Hello World";
  printSuccess(lengthOfLastWord(s1) == 5);

  std::string s2 = "   fly me    to   the moon   ";
  printSuccess(lengthOfLastWord(s2) == 4);

  std::string s3 = "luffy is still joyboy";
  printSuccess(lengthOfLastWord(s3) == 6);

  std::string s4 = "a";
  printSuccess(lengthOfLastWord(s4) == 1);

  std::string s5 = "aa";
  printSuccess(lengthOfLastWord(s5) == 2);

  return 0;
}
