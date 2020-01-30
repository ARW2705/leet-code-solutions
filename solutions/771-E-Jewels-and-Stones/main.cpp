#include <iostream>
#include <string>

void printResult(std::string& j, std::string& s, int result, int expected) {
  std::cout
    << "For types of stones "
    << j
    << ", and possessed stones "
    << s
    << ", have "
    << result
    << " jewels, expected "
    << expected
    << (result == expected ? "\nPASS": "\nFAIL")
    << "\n";
}

int numJewelsInStones(std::string J, std::string S) {
    int total = 0;
    for (char c : S) {
        total += J.find(c) != std::string::npos;
    }
    return total;
}

int main() {
  std::string j1 = "aA";
  std::string s1 = "aAAbbbb";
  printResult(j1, s1, numJewelsInStones(j1, s1), 3);

  std::string j2 = "z";
  std::string s2 = "ZZ";
  printResult(j2, s2, numJewelsInStones(j2, s2), 0);
  return 0;
}
