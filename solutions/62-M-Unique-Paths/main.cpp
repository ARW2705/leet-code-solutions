#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

using namespace std;

// simple recursion
// int uniquePaths(int m, int n) {
//   ++steps;
//   if (m == 1 && n == 1) return 1;

//   int tryDown = m > 1 ? uniquePaths(m - 1, n) : 0;
//   int tryRight = n > 1 ? uniquePaths(m, n - 1) : 0;
//   return tryDown + tryRight;
// }

// memo with map
// int uniquePathsHelper(int m, int n, unordered_map<string, int>& previous) {
//   ++steps;
//   if (m == 1 && n == 1) return 1;

//   string key = to_string(m) + "," + to_string(n);
//   unordered_map<string, int>::iterator iter = previous.find(key);
//   if (iter != previous.end()) return iter->second;

//   int tryDown = m > 1 ? uniquePathsHelper(m - 1, n, previous) : 0;
//   int tryRight = n > 1 ? uniquePathsHelper(m, n - 1, previous) : 0;
//   previous.insert(make_pair(key, tryDown + tryRight));
//   return tryDown + tryRight;
// }

// int uniquePaths(int m, int n) {
//   unordered_map<string, int> previous;
//   return uniquePathsHelper(m, n, previous);
// }

// memo with matrix
int uniquePathsHelper(int m, int n, vector<vector<int>>& previous) {
  if (m == 1 && n == 1) return 1;
  if (previous[m][n] != -1) return previous[m][n];

  int tryDown = m > 1 ? uniquePathsHelper(m - 1, n, previous) : 0;
  int tryRight = n > 1 ? uniquePathsHelper(m, n - 1, previous) : 0;
  previous[m][n] = tryDown + tryRight;
  return tryDown + tryRight;
}

int uniquePaths(int m, int n) {
  vector<vector<int>> previous(m + 1, vector<int>(n + 1, -1));
  return uniquePathsHelper(m, n, previous);
}

int main() {
  printSuccess(uniquePaths(3, 7) == 28);
  printSuccess(uniquePaths(3, 2) == 3);
  printSuccess(uniquePaths(51, 9) == 1916797311);
  printSuccess(uniquePaths(23, 12) == 193536720);

  return 0;
}
