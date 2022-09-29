#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string pushDominoes(std::string dominoes) {
  int size = dominoes.size();
  for (int i = 0; i < size; ++i) {
    if (dominoes[i] == '.') {
      int start = i - 1;
      int end = i + 1;
      while (end < size && dominoes[end] == '.') {
        ++end;
      }

      bool fromLeft = start >= 0 && dominoes[start] == 'R';
      bool fromRight = end < size && dominoes[end] == 'L';
      int leftEdge = start + 1, rightEdge = end - 1;
      if (fromLeft || fromRight) {
        while (leftEdge < rightEdge) {
          if (fromLeft) dominoes[leftEdge++] = 'R';
          if (fromRight) dominoes[rightEdge--] = 'L';
        }

        if (leftEdge == rightEdge && fromLeft ^ fromRight) {
          dominoes[leftEdge] = fromLeft ? 'R' : 'L';
        }
      }

      i = end;
    }
  }

  return dominoes;
}

int main() {
  std::string s1 = "RR.L";
  std::string e1 = "RR.L";
  printSuccess(e1.compare(pushDominoes(s1)) == 0);

  std::string s2 = ".L.R...LR..L..";
  std::string e2 = "LL.RR.LLRRLL..";
  printSuccess(e2.compare(pushDominoes(s2)) == 0);

  std::string s3 = "L.RL..L.LR..";
  std::string e3 = "L.RLLLLLLRRR";
  printSuccess(e3.compare(pushDominoes(s3)) == 0);

  return 0;
}
