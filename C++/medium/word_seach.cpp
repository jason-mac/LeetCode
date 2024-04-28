/*Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.*/
// accepted solution
class Solution {

public:
  bool outOfBounds(int i, int j, vector<vector<char>> &board) {
    return (i == -1 || j == -1 || i == board.size() || j == board[0].size());
  }
  void dfs(int i, int j, vector<vector<char>> &board, string word, bool &found,
           int index = 0) {
    if (index == word.size()) {
      found = true;
      return;
    }
    if (outOfBounds(i, j, board))
      return;
    if (board[i][j] != word[index])
      return;
    char temp = board[i][j];
    board[i][j] = '$';
    dfs(i + 1, j, board, word, found, index + 1);
    dfs(i - 1, j, board, word, found, index + 1);
    dfs(i, j + 1, board, word, found, index + 1);
    dfs(i, j - 1, board, word, found, index + 1);
    board[i][j] = temp;
  }
  bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          bool found = false;
          dfs(i, j, board, word, found);
          if (found) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
