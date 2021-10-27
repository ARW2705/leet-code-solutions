#include <iostream>
#include <vector>

bool isValidHorizontal(std::vector<std::vector<char>>& board, int startRow, int startCol) {
  char baseChar = board[startRow][startCol];
  for (int col = 0; col < board[startRow].size(); ++col) {
    if (col != startCol && board[startRow][col] == baseChar) {
      return false;
    }
  }
  return true;
}

bool isValidVertical(std::vector<std::vector<char>>& board, int startRow, int startCol) {
  char baseChar = board[startRow][startCol];
  for (int row = 0; row < board.size(); ++row) {
    if (row != startRow && board[row][startCol] == baseChar) {
      return false;
    }
  }
  return true;
}

bool isValidSquare(std::vector<std::vector<char>>& board, int startRow, int startCol) {
  char baseChar = board[startRow][startCol];
  int rowSquare = startRow / 3;
  int colSquare = startCol / 3;
  for (int row = (rowSquare * 3); row < (rowSquare * 3 + 3); ++row) {
    for (int col = (colSquare * 3); col < (colSquare * 3 + 3); ++col) {
      if (row != startRow && col != startCol && board[row][col] == baseChar) {
        return false;
      }
    }
  }
  return true;
}

bool isValidPerRule(std::vector<std::vector<char>>& board, int row, int col) {
  return (
    board[row][col] == '.'
    || (
      isValidHorizontal(board, row, col)
      && isValidVertical(board, row, col)
      && isValidSquare(board, row, col)
    )
  );
}

bool isValidSudoku(std::vector<std::vector<char>>& board) {
  for (int row = 0; row < board.size(); ++row) {
    for (int col = 0; col < board[row].size(); ++col) {
      if (!isValidPerRule(board, row, col)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  std::vector<std::vector<char>> s1 {
     {'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}
  };
  std::cout << (isValidSudoku(s1) ? "PASS" : "FAIL") << "\n";

  std::vector<std::vector<char>> s2 {
     {'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}
  };
  std::cout << (!isValidSudoku(s2) ? "PASS" : "FAIL") << std::endl;
  return 0;
}
