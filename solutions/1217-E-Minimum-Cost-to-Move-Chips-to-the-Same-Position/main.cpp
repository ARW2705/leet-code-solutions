#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int minCostToMoveChips(std::vector<int>& position) {
  int evenChips = 0, oddChips = 0;
  for (int pos : position) {
    if (pos % 2 == 0) ++evenChips;
    else ++oddChips;
  }
  return std::min(evenChips, oddChips);
}

int main() {
  std::vector<int> v1 { 1, 2, 3 };
  int r1 = minCostToMoveChips(v1);
  std::cout << r1 << "\n";
  printSuccess(r1 == 1);

  std::vector<int> v2 { 1, 1000000000 };
  int r2 = minCostToMoveChips(v2);
  std::cout << r2 << "\n";
  printSuccess(r2 == 1);

  std::vector<int> v3 { 2,2,2,3,3 };
  int r3 = minCostToMoveChips(v3);
  std::cout << r3 << "\n";
  printSuccess(r3 == 2);

  return 0;
}
