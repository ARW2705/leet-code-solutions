#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

int countSegments(std::string s) {
  int size = s.size();
  int count = 0;
  bool startWord = true;
  for (int i = 0; i < size; ++i) {
    if (s[i] != ' ' && startWord) {
      ++count;
      startWord = false;
    } else if (s[i] == ' ') {
      startWord = true;
    }
  }
  return count;
}

int main() {
  std::string s1 = "Hello, my name is John";
  int r1 = countSegments(s1);
  std::cout << r1 << "\n";
  printSuccess(r1 == 5);

  std::string s2 = "Hello";
  int r2 = countSegments(s2);
  std::cout << r2 << "\n";
  printSuccess(r2 == 1);

  std::string s3 = "    ";
  int r3 = countSegments(s3);
  std::cout << r3 << "\n";
  printSuccess(r3 == 0);

  std::string s4 = ", , , ,        a, eaefa";
  int r4 = countSegments(s4);
  std::cout << r4 << "\n";
  printSuccess(r4 == 6);

  std::string s5 = "a";
  int r5 = countSegments(s5);
  std::cout << r5 << "\n";
  printSuccess(r5 == 1);

  std::string s6 = "   foo   bar";
  int r6 = countSegments(s6);
  std::cout << r6 << "\n";
  printSuccess(r6 == 2);

  return 0;
}
