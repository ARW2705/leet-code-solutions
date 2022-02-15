#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"

// track start/end of each char
// std::vector<int> partitionLabels(std::string s) {
//   std::vector<std::pair<int, int>> indices;
//   std::vector<int> charMap(26, -1);
//   for (int i = 0; i < s.size(); ++i) {
//     int index = charMap[s[i] - 'a'];
//     if (index == -1) {
//       indices.push_back(std::make_pair(i, i));
//       charMap[s[i] - 'a'] = indices.size() - 1;
//     } else {
//       indices[charMap[s[i] - 'a']].second = i;
//     }
//   }
//
//   std::vector<int> partitionSizes;
//   int currentStart = std::numeric_limits<int>::max();
//   int currentEnd = std::numeric_limits<int>::min();
//   for (int i = 0; i < indices.size() + 1; ++i) {
//     if (i == indices.size()) {
//       partitionSizes.push_back(currentEnd - currentStart + 1);
//     } else if (indices[i].first != -1) {
//       if (indices[i].first < currentStart && indices[i].second > currentEnd) {
//         currentStart = indices[i].first;
//         currentEnd = indices[i].second;
//       } else if (indices[i].first > currentEnd) {
//         partitionSizes.push_back(currentEnd - currentStart + 1);
//         currentStart = indices[i].first;
//         currentEnd = indices[i].second;
//       } else if (indices[i].first < currentStart) {
//         currentStart = indices[i].first;
//       } else if (indices[i].second > currentEnd) {
//         currentEnd = indices[i].second;
//       }
//     }
//   }
//
//   return partitionSizes;
// }


// track only end of each char
std::vector<int> partitionLabels(std::string s) {
  int size = s.size();
  std::vector<int> lastIndices(26, -1);
  for (int i = size - 1; i >= 0; --i) {
    if (lastIndices[s[i] - 'a'] == -1) {
      lastIndices[s[i] - 'a'] = i;
    }
  }

  std::vector<int> partitionSizes;
  int minIndex = -1;
  int partitionSize = 0;
  for (int i = 0; i < size; ++i) {
    minIndex = std::max(minIndex, lastIndices[s[i] - 'a']);
    ++partitionSize;
    if (i == minIndex) {
      partitionSizes.push_back(partitionSize);
      minIndex = -1;
      partitionSize = 0;
    }
  }

  return partitionSizes;
}

int main() {
  std::string s1 = "ababcbacadefegdehijhklij";
  std::vector<int> r1 = partitionLabels(s1);
  printVector(r1);

  std::string s2 = "eccbbbbdec";
  std::vector<int> r2 = partitionLabels(s2);
  printVector(r2);

  std::string s3 = "zyxwvut";
  std::vector<int> r3 = partitionLabels(s3);
  printVector(r3);

  std::string s4 = "zyxabcz";
  std::vector<int> r4 = partitionLabels(s4);
  printVector(r4);

  return 0;
}
