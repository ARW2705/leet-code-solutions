#include <iostream>
#include <string>
#include <cmath>
#include "../../utilities/print-success.cpp"

std::string intToRoman(int num) {
  char mainSymbols[4] { 'I', 'X', 'C', 'M' };
  char secondarySymbols[3] { 'V', 'L', 'D' };
  std::string romanNumeral = "";
  std::string numStr = std::to_string(num);
  int size = numStr.size();
  int currentPlace = size - 1;
  int digit;

  for (int i = 0; i < size; ++i) {
    digit = numStr[i] - '0';
    if (digit < 4) {
      romanNumeral += std::string(digit, mainSymbols[currentPlace]);
    } else if (digit == 4) {
      romanNumeral += mainSymbols[currentPlace];
      romanNumeral += secondarySymbols[currentPlace];
    } else if (digit == 5) {
      romanNumeral += secondarySymbols[currentPlace];
    } else if (digit < 9) {
      romanNumeral += secondarySymbols[currentPlace];
      romanNumeral += std::string(digit - 5, mainSymbols[currentPlace]);
    } else if (digit == 9) {
      romanNumeral += mainSymbols[currentPlace];
      romanNumeral += mainSymbols[currentPlace + 1];
    }

    --currentPlace;
  }

  return romanNumeral;
}

int main() {
  printSuccess(intToRoman(4).compare("IV") == 0);
  printSuccess(intToRoman(3).compare("III") == 0);
  printSuccess(intToRoman(58).compare("LVIII") == 0);
  printSuccess(intToRoman(1994).compare("MCMXCIV") == 0);
  printSuccess(intToRoman(1000).compare("M") == 0);
  return 0;
}
