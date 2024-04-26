// 130. Surrounded Regions, Accepted April 25th, 2024
class Solution {

public:
  bool outOfBounds(int i, int j, vector<vector<char>> &board) {
    return i == -1 || j == -1 || i == board.size() || j == board[0].size();
  }
  void dfs(int i, int j, vector<vector<char>> &board) {
    if (outOfBounds(i, j, board))
      return;
    if (board[i][j] == 'X')
      return;
    if (board[i][j] == ' ')
      return;
    if (board[i][j] == 'O')
      board[i][j] = ' ';
    dfs(i + 1, j, board);
    dfs(i, j + 1, board);
    dfs(i - 1, j, board);
    dfs(i, j - 1, board);
  }
  void solve(vector<vector<char>> &board) {
    // iterate top row

    for (int i = 0; i < board[0].size(); i++) {
      if (board[0][i] == 'O') {
        dfs(0, i, board);
      }
    }
    // iterate left column
    for (int i = 0; i < board.size(); i++) {
      if (board[i][0] == 'O') {
        dfs(i, 0, board);
      }
    }
    // iterate bottomr row
    for (int i = 0; i < board[0].size(); i++) {
      if (board[board.size() - 1][i] == 'O') {
        dfs(board.size() - 1, i, board);
      }
    }
    // itereate right column
    for (int i = 0; i < board.size(); i++) {
      if (board[i][board[0].size() - 1] == 'O') {
        dfs(i, board[0].size() - 1, board);
      }
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == ' ')
          board[i][j] = 'O';
      }
    }
  }
}
