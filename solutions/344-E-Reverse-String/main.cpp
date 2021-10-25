#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

void reverseString(std::vector<char>& s) {
  int size = s.size();
  for (int i = 0; i < size / 2; ++i) {
    std::swap(s[i], s[size - i - 1]);
  }
}

int main() {
  std::vector<char> t1 { 'h', 'e', 'l', 'l', 'o' };
  std::vector<char> e1 { 'o', 'l', 'l', 'e', 'h' };
  reverseString(t1);
  printVector(t1);
  std::cout << (compareVector(t1, e1) ? "PASS" : "FAIL") << "\n";
  std::vector<char> t2 { 'H', 'a', 'n', 'n', 'a', 'h' };
  std::vector<char> e2 { 'h', 'a', 'n', 'n', 'a', 'H' };
  reverseString(t2);
  printVector(t2);
  std::cout << (compareVector(t2, e2) ? "PASS" : "FAIL") << "\n";
  return 0;
}
