#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

bool isIsomorphic(std::string s, std::string t) {
  std::vector<bool> encounteredChars(256, false);
  std::vector<int> charMap(256, -1);
  char sChar, tChar;
  for (int i = 0; i < s.size(); ++i) {
    sChar = s[i];
    tChar = t[i];
    if ((encounteredChars[sChar] && sChar != charMap[tChar]) || (!encounteredChars[sChar] && charMap[tChar] != -1)) {
      return false;
    } else if (charMap[tChar] == -1) {
      charMap[tChar] = sChar;
    }
    encounteredChars[sChar] = true;
  }
  return true;
}

int main() {
  std::string s1a = "egg";
  std::string s2a = "add";
  printSuccess(isIsomorphic(s1a, s2a));

  std::string s1b = "foo";
  std::string s2b = "bar";
  printSuccess(!isIsomorphic(s1b, s2b));

  std::string s1c = "paper";
  std::string s2c = "title";
  printSuccess(isIsomorphic(s1c, s2c));

  std::string s1d = "badc";
  std::string s2d = "baba";
  printSuccess(!isIsomorphic(s1d, s2d));

  return 0;
}
