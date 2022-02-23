#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

std::vector<int> decode(std::vector<int>& encoded, int first) {
  std::vector<int> decoded(encoded.size() + 1);
  decoded[0] = first;
  for (int i = 1; i < decoded.size(); ++i) {
    decoded[i] = encoded[i - 1] ^ decoded[i - 1];
  }
  printVector(decoded);
  return decoded;
}

int main() {
  std::vector<int> v1 { 1, 2, 3 };
  std::vector<int> e1 { 1, 0, 2, 1 };
  std::vector<int> r1 = decode(v1, 1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 6, 2, 7, 3 };
  std::vector<int> e2 { 4, 2, 0, 7, 4 };
  std::vector<int> r2 = decode(v2, 4);
  printSuccess(compareVector(e2, r2));

  return 0;
}
