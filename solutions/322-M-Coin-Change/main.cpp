#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>
#include <unordered_map>
#include <map>
#include "../../utilities/print-success.cpp"

// compare speed with map and unordered map
int coinChangeHelperVector(std::vector<int>& memo, std::vector<int>& coins, int amount) {
  if (!amount) {
    return 0;
  } else if (memo[amount]) {
    return memo[amount];
  } else {
    int minCoins = std::numeric_limits<int>::max();
    for (int coin : coins) {
      int nextAmount = amount - coin;
      if (nextAmount >= 0) {
        int count = coinChangeHelperVector(memo, coins, nextAmount);
        if (count != -1) {
          minCoins = std::min(minCoins, count + 1);
        }
      }
    }

    int result = minCoins == std::numeric_limits<int>::max() ? -1 : minCoins;
    memo[amount] = result;
    return result;
  }
}

int coinChangeVector(std::vector<int>& coins, int amount) {
  std::vector<int> memo(amount + 1);
  std::sort(coins.begin(), coins.end());
  return coinChangeHelperVector(memo, coins, amount);
}

// compare speed with map and vector
int coinChangeHelperUnorderedMap(std::unordered_map<int, int>& memo, std::vector<int>& coins, int amount) {
  if (!amount) {
    return 0;
  } else if (memo[amount]) {
    return memo[amount];
  } else {
    int minCoins = std::numeric_limits<int>::max();
    for (int coin : coins) {
      int nextAmount = amount - coin;
      if (nextAmount >= 0) {
        int count = coinChangeHelperUnorderedMap(memo, coins, nextAmount);
        if (count != -1) {
          minCoins = std::min(minCoins, count + 1);
        }
      }
    }

    int result = minCoins == std::numeric_limits<int>::max() ? -1 : minCoins;
    memo[amount] = result;
    return result;
  }
}

int coinChangeUnorderedMap(std::vector<int>& coins, int amount) {
  std::unordered_map<int, int> memo;
  std::sort(coins.begin(), coins.end());
  return coinChangeHelperUnorderedMap(memo, coins, amount);
}

// compare speed with unordered map and vector
int coinChangeHelperMap(std::map<int, int>& memo, std::vector<int>& coins, int amount) {
  if (!amount) {
    return 0;
  } else if (memo[amount]) {
    return memo[amount];
  } else {
    int minCoins = std::numeric_limits<int>::max();
    for (int coin : coins) {
      int nextAmount = amount - coin;
      if (nextAmount >= 0) {
        int count = coinChangeHelperMap(memo, coins, nextAmount);
        if (count != -1) {
          minCoins = std::min(minCoins, count + 1);
        }
      }
    }

    int result = minCoins == std::numeric_limits<int>::max() ? -1 : minCoins;
    memo[amount] = result;
    return result;
  }
}

int coinChangeMap(std::vector<int>& coins, int amount) {
  std::map<int, int> memo;
  std::sort(coins.begin(), coins.end());
  return coinChangeHelperMap(memo, coins, amount);
}

// recursive w/ dp memo
int coinChangeHelper(std::vector<int>& memo, std::vector<int>& coins, int amount) {
  if (!amount) {
    return 0;
  } else if (memo[amount]) {
    return memo[amount];
  } else {
    int minCoins = std::numeric_limits<int>::max();
    for (int coin : coins) {
      int nextAmount = amount - coin;
      if (nextAmount >= 0) {
        int count = coinChangeHelper(memo, coins, nextAmount);
        if (count != -1) {
          minCoins = std::min(minCoins, count + 1);
        }
      }
    }

    int result = minCoins == std::numeric_limits<int>::max() ? -1 : minCoins;
    memo[amount] = result;
    return result;
  }
}

int coinChange(std::vector<int>& coins, int amount) {
  std::vector<int> memo(amount + 1);
  std::sort(coins.begin(), coins.end());
  return coinChangeHelper(memo, coins, amount);
}

// backtracking
// int coinChangeHelper(std::vector<int>& coins, int amount) {
//   if (!amount) return 0;
//   int size = coins.size();
//   if (!size) return -1;
//   int minCoins = std::numeric_limits<int>::max();
//
//   for (int i = size - 1; i >= 0; --i) {
//     int coin = coins[i];
//     coins.erase(coins.begin() + i);
//     int maxTimes = amount / coin;
//     for (int j = maxTimes; j > 0; --j) {
//       int remainingAmount = amount - (coin * j);
//       if (!remainingAmount && j < minCoins) {
//         minCoins = j;
//       } else if (remainingAmount > 0) {
//         int nextCoinAttempt = coinChangeHelper(coins, remainingAmount);
//         if (nextCoinAttempt != -1 && (nextCoinAttempt + j) < minCoins) {
//           minCoins = nextCoinAttempt + j;
//         }
//       }
//     }
//     coins.insert(coins.begin() + i, coin);
//   }
//
//   return minCoins == std::numeric_limits<int>::max() ? -1 : minCoins;
// }

// int coinChange(std::vector<int>& coins, int amount) {
//   std::sort(coins.begin(), coins.end());
//   int count = coinChangeHelper(coins, amount);
//   std::cout << count << "\n";
//   return count;
// }

int main() {
  std::vector<int> v { 3, 5 };
  printSuccess(coinChange(v, 19) == 5);

  std::vector<int> v1 { 1, 2, 5 };
  printSuccess(coinChange(v1, 11) == 3);

  std::vector<int> v2 { 2 };
  printSuccess(coinChange(v2, 3) == -1);

  std::vector<int> v3 { 1, 5, 10 };
  printSuccess(coinChange(v3, 51) == 6);

  std::vector<int> v4 { 1, 2, 25 };
  printSuccess(coinChange(v4, 24) == 12);

  std::vector<int> v5 { 1 };
  printSuccess(coinChange(v5, 0) == 0);

  std::vector<int> v6 { 186, 419, 83, 408 };
  printSuccess(coinChange(v6, 6249) == 20);

  std::vector<int> v7 { 3, 7, 405, 436 };
  printSuccess(coinChange(v7, 8839) == 25);

  std::cout << "\n";

  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point finish;
  std::chrono::duration<double> time;
  int result;

  std::vector<int> vTimeTest { 3, 7, 405, 436 };

  std::cout << "Vector";
  start = std::chrono::high_resolution_clock::now();
  result = coinChangeVector(vTimeTest, 8839);
  finish = std::chrono::high_resolution_clock::now();
  time = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
  std::cout << " took " << time.count() << " seconds\n\n";

  start = std::chrono::high_resolution_clock::now();
  std::cout << "Unordered map";
  result = coinChangeUnorderedMap(vTimeTest, 8839);
  finish = std::chrono::high_resolution_clock::now();
  time = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
  std::cout << " took " << time.count() << " seconds\n\n";

  start = std::chrono::high_resolution_clock::now();
  std::cout << "Map";
  result = coinChangeMap(vTimeTest, 8839);
  finish = std::chrono::high_resolution_clock::now();
  time = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start);
  std::cout << " took " << time.count() << " seconds\n\n";

  return 0;
}
