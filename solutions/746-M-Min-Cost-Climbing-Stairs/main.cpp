#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../utilities/print-success.cpp"

using namespace std;

int minCostClimbingStairsHelper(vector<int>& cost, int index, unordered_map<int, int>& memo) {
  if (index > 0 && index >= cost.size()) return 0;

  int currentCost = index < 0 ? 0 : cost[index];
  int oneStep, twoStep;
  if (memo.find(index + 1) == memo.end()) {
    oneStep = minCostClimbingStairsHelper(cost, index + 1, memo);
    memo[index + 1] = oneStep;
  } else {
    oneStep = memo[index + 1];
  }
  
  if (memo.find(index + 2) == memo.end()) {
    twoStep = minCostClimbingStairsHelper(cost, index + 2, memo);
    memo[index + 2] = twoStep;
  } else {
    twoStep = memo[index + 2];
  }

  return currentCost + min(oneStep, twoStep);
}

int minCostClimbingStairs(vector<int>& cost) {
  unordered_map<int, int> memo;
  return minCostClimbingStairsHelper(cost, -1, memo);
}

int main() {
  vector<int> v1 { 10, 15, 20 };
  printSuccess(minCostClimbingStairs(v1) == 15);

  vector<int> v2 { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
  printSuccess(minCostClimbingStairs(v2) == 6);

  return 0;
}
