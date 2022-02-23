#include <iostream>
#include <string>
#include <unordered_map>
#include "../../utilities/print-success.cpp"

int countPoints(std::string rings) {
  std::unordered_map<char, int> rgb { { 'R', 0 }, { 'G', 1 }, { 'B', 2 } };
  bool rods[10][3] = { false };

  int size = rings.size();
  for (int i = 0; i < size - 1; i += 2) {
    rods[rings[i + 1] - '0'][rgb[rings[i]]] = true;
  }

  int rodCount = 0;
  for (int i = 0; i < 10; ++i) {
    if (rods[i][0] && rods[i][1] && rods[i][2]) {
      ++rodCount;
    }
  }

  return rodCount;
}

int main() {
  std::string s1 = "B0B6G0R6R0R6G9";
  printSuccess(countPoints(s1) == 1);

  std::string s2 = "B0R0G0R9R0B0G0";
  printSuccess(countPoints(s2) == 1);

  std::string s3 = "G4";
  printSuccess(countPoints(s3) == 0);

  return 0;
}
