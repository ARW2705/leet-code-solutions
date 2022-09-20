#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

bool lemonadeChange(std::vector<int>& bills) {
  int fives = 0, tens = 0;
  for (int bill : bills) {
    if (bill == 5) {
      ++fives;
    } else if (bill == 10) {
      if (fives == 0) return false;
      ++tens;
      --fives;
    } else {
      if (tens == 0 && fives > 2) {
        fives -= 3;
      } else if (tens > 0 && fives > 0) {
        --tens;
        --fives;
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  std::vector<int> v1 { 5, 5, 5, 10, 20 };
  printSuccess(lemonadeChange(v1));

  std::vector<int> v2 { 5, 5, 10, 10, 20 };
  printSuccess(!lemonadeChange(v2));

  std::vector<int> v3 {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
  printSuccess(lemonadeChange(v3));

  return 0;
}
