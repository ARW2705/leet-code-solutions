#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

// std::vector<int> shortestToChar(std::string s, char c) {
//   int size = s.size();
//   std::vector<int> distances(size, size);
//   for (int i = 0; i < size; ++i) {
//     if (s[i] == c) {
//       for (int j = 0; j < size; ++j) {
//         if (i - j >= 0) distances[i - j] = std::min(j, distances[i - j]);
//         if (i + j < size) distances[i + j] = std::min(j, distances[i + j]);
//       }
//     }
//   }
//   return distances;
// }

std::vector<int> shortestToChar(std::string s, char c) {
  int size = s.size();
  std::vector<int> distances(size, size);
  for (int i = 0; i < size; ++i) {
    if (s[i] == c) {
      distances[i] = 0;
      int distance = 1, toLeft = i, toRight = i;
      do {
        --toLeft;
        if (toLeft >= 0) {
          if (s[toLeft] == c) {
            toLeft = 0;
          } else {
            distances[i - distance] = std::min(distance, distances[i - distance]);
          }
        }

        ++toRight;
        if (toRight < size) {
          if (s[toRight] == c) {
            toRight = size;
          } else {
            distances[i + distance] = std::min(distance, distances[i + distance]);
          }
        }

        ++distance;
      } while (toLeft >= 0 || toRight < size);
    }
  }
  return distances;
}

int main() {
  std::string s1 = "aaab";
  char c1 = 'b';
  std::vector<int> e1 { 3, 2, 1, 0 };
  std::vector<int> r1 = shortestToChar(s1, c1);
  printSuccess(compareVector(r1, e1));

  std::string s2 = "loveleetcode";
  char c2 = 'e';
  std::vector<int> e2 { 3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0 };
  std::vector<int> r2 = shortestToChar(s2, c2);
  printSuccess(compareVector(r2, e2));

  std::string s3 = "aaba";
  char c3 = 'b';
  std::vector<int> e3 { 2, 1, 0, 1 };
  std::vector<int> r3 = shortestToChar(s3, c3);
  printSuccess(compareVector(r3, e3));

  return 0;
}
