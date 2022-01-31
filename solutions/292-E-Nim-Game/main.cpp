#include <iostream>
#include "../../utilities/print-success.cpp"

bool canWinNim(int n) {
  return n % 4 != 0;
}

int main() {
  bool r1 = canWinNim(4);
  printSuccess(!r1);

  bool r2 = canWinNim(1);
  printSuccess(r2);

  bool r3 = canWinNim(2);
  printSuccess(r3);

  bool r4 = canWinNim(9);
  printSuccess(r4);

  bool r5 = canWinNim(8);
  printSuccess(!r5);

  bool r6 = canWinNim(12);
  printSuccess(!r6);

  return 0;
}
