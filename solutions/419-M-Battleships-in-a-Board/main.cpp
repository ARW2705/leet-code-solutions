#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

// void explore(std::vector<std::vector<char>>& board, int row, int col) {
//   if (board[row][col] != 'X') return;

//   board[row][col] = '.';
//   if (row > 0) {
//     explore(board, row - 1, col);
//   }
//   if (row < board.size() - 1) {
//     explore(board, row + 1, col);
//   }
//   if (col > 0) {
//     explore(board, row, col - 1);
//   }
//   if (col < board[0].size() - 1) {
//     explore(board, row, col + 1);
//   }
// }

// int countBattleships(std::vector<std::vector<char>>& board) {
//   int count = 0;
//   for (int row = 0; row < board.size(); ++row) {
//     for (int col = 0; col < board[row].size(); ++col) {
//       if (board[row][col] == 'X') {
//         ++count;
//         explore(board, row, col);
//       }
//     }
//   }
//   return count;
// }

int countBattleships(std::vector<std::vector<char>>& board) {
  int count = 0;
  for (int row = 0; row < board.size(); ++row) {
    for (int col = 0; col < board[row].size(); ++col) {
      if (
        board[row][col] == 'X'
        && (row == 0 || board[row - 1][col] != 'X')
        && (col == 0 || board[row][col - 1] != 'X')
      ) {
        ++count;
      }
    }
  }
  return count;
}

int main() {
  std::vector<std::vector<char>> b1 {
    {'X','.','.','X'},
    {'.','.','.','X'},
    {'.','.','.','X'}
  };
  printSuccess(countBattleships(b1) == 2);

  std::vector<std::vector<char>> b2 { {'.'} };
  printSuccess(countBattleships(b2) == 0);

  return 0;
}
