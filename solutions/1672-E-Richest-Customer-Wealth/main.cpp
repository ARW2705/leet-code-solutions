#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int maximumWealth(std::vector<std::vector<int>>& accounts) {
  int maxWealth = 0;
  int accountWealth;
  for (std::vector<int> account : accounts) {
    accountWealth = 0;
    for (int amount : account) {
      accountWealth += amount;
    }
    if (accountWealth > maxWealth) {
      maxWealth = accountWealth;
    }
  }
  return maxWealth;
}

int main() {
  std::vector<std::vector<int>> v1 { { 1, 2, 3 }, { 3, 2, 1 } };
  printSuccess(maximumWealth(v1) == 6);

  std::vector<std::vector<int>> v2 { { 1, 5 }, { 7, 3 }, { 3, 5 } };
  printSuccess(maximumWealth(v2) == 10);

  std::vector<std::vector<int>> v3 { { 2, 8, 7 }, { 7, 1, 3 }, { 1, 9, 5 } };
  printSuccess(maximumWealth(v3) == 17);

  return 0;
}
