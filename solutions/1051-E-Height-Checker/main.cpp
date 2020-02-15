#include <iostream>
#include <vector>
#include <algorithm>

int heightChecker(std::vector<int>& heights) {
  std::vector<int> heightsSorted(heights);
  std::sort(heightsSorted.begin(), heightsSorted.end());
  int moves = 0;
  for (size_t i=0; i < heights.size(); ++i) {
    if (heights[i] != heightsSorted[i]) {
      ++moves;
    }
  }
  return moves;
}

int main() {
  std::vector<int> test { 1, 1, 4, 2, 1, 3 };
  int result = heightChecker(test);
  std::cout << result << ": " << (result == 3 ? "PASS": "FAIL") << "\n";
  return 0;
}
