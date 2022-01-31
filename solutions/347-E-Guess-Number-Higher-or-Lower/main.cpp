#include <iostream>
#include <limits>
#include "../../utilities/print-success.cpp"

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int pick = 0;

int guess(int num) {
  if (pick < num) {
    return -1;
  } else if (pick > num) {
    return 1;
  } else {
    return 0;
  }
}

int guessNumber(int n) {
  int min = 1, max = std::numeric_limits<int>::max();
  int myGuess = n, highLow;
  do {
    highLow = guess(myGuess);
    if (highLow == -1) {
      max = myGuess;
      myGuess = (myGuess - min) / 2 + min;
    } else if (highLow == 1) {
      min = myGuess;
      myGuess = (max - myGuess) / 2 + myGuess + 1;
    }
  } while (highLow != 0);
  return myGuess;
}

int main() {
  pick = 6;
  printSuccess(guessNumber(11) == pick);
  pick = 1;
  printSuccess(guessNumber(1) == pick);
  pick = 1;
  printSuccess(guessNumber(2) == pick);
  pick = 2147483647;
  printSuccess(guessNumber(5) == pick);

  return 0;
}
