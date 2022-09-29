#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "../../utilities/print-matrix.cpp"

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
  std::unordered_map<std::string, std::vector<std::string>> groupMap;

  for (int i = 0; i < strs.size(); ++i) {
    std::string index = std::string(strs[i]);
    std::sort(index.begin(), index.end());
    groupMap[index].push_back(strs[i]);
  }

  std::vector<std::vector<std::string>> groups;
  for (auto group : groupMap) {
    groups.push_back(group.second);
  }

  return groups;
}

int main() {
  std::vector<std::string> v1 { "eat", "tea", "tan", "ate", "nat", "bat" };
  std::vector<std::vector<std::string>> r1 = groupAnagrams(v1);
  printMatrix(r1);

  std::vector<std::string> v2 { "" };
  std::vector<std::vector<std::string>> r2 = groupAnagrams(v2);
  printMatrix(r2);

  std::vector<std::string> v3 { "a" };
  std::vector<std::vector<std::string>> r3 = groupAnagrams(v3);
  printMatrix(r3);

  return 0;
}
