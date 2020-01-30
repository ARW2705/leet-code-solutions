#include <iostream>
#include <vector>
#include <cmath>

int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
  int totalTime = 0;
  for (int i=0; i < points.size() - 1; ++i) {
    totalTime += std::max(
      std::abs(points[i][0] - points[i + 1][0]),
      std::abs(points[i][1] - points[i + 1][1])
    );
  }
  return totalTime;
}

int main() {
  std::vector<std::vector<int>> ex1 {
    { 1, 1 },
    { 3, 4 },
    { -1, 0 }
  };
  int result1 = minTimeToVisitAllPoints(ex1);
  std::cout
    << "Min time to visit all points for ex1: "
    << result1
    << " seconds: "
    << (result1 == 7 ? "PASS": "FAIL")
    << "\n";

  std::vector<std::vector<int>> ex2 {
    { 3, 2 },
    { -2, 2 }
  };
  int result2 = minTimeToVisitAllPoints(ex2);
  std::cout
    << "Min time to visit all points for ex2: "
    << result2
    << " seconds: "
    << (result2 == 5 ? "PASS": "FAIL")
    << "\n";

  return 0;
}
