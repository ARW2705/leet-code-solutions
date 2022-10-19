#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../../utilities/print-vector.cpp"

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
  int size = s.size(), seqSpan = 10;
  if (size < seqSpan) return {};

  std::unordered_map<std::string, int> sequences;
  std::vector<std::string> repeatedSequences;
  std::string sequence;
  for (int i = 0; i < size - seqSpan + 1; ++i) {
    sequence = s.substr(i, seqSpan);
    if (sequences[sequence]++ == 1) {
      repeatedSequences.push_back(sequence);
    }
  }

  return repeatedSequences;
}

int main() {
  std::string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  std::vector<std::string> r1 = findRepeatedDnaSequences(s1);
  printVector(r1);

  std::string s2 = "AAAAAAAAAAAAA";
  std::vector<std::string> r2 = findRepeatedDnaSequences(s2);
  printVector(r2);

  std::string s3 = "A";
  std::vector<std::string> r3 = findRepeatedDnaSequences(s3);
  printVector(r3);

  std::string s4 = "AAAAAAAAAAA";
  std::vector<std::string> r4 = findRepeatedDnaSequences(s4);
  printVector(r4);

  return 0;
}
