#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string truncateSentence(std::string s, int k) {
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') --k;
    if (k == 0) return s.substr(0, i);
  }

  return s;
}

int main() {
  std::string s1 = "Hello how are you Contestant";
  std::string e1 = "Hello how are you";
  std::string r1 = truncateSentence(s1, 4);
  printSuccess(r1.compare(e1) == 0);

  std::string s2 = "What is the solution to this problem";
  std::string e2 = "What is the solution";
  std::string r2 = truncateSentence(s2, 4);
  printSuccess(r2.compare(e2) == 0);

  std::string s3 = "chopper is not a tanuki";
  std::string e3 = "chopper is not a tanuki";
  std::string r3 = truncateSentence(s3, 5);
  printSuccess(r3.compare(e3) == 0);

  return 0;
}
