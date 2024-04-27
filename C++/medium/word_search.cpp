#include <unordered_set>
// accepted
class Solution {

public:
  bool outOfBounds(int i, int j, vector<vector<char>> &grid) {
    return i == -1 || j == -1 || i == grid.size() || j == grid[0].size();
  }
  void dfs(int i, int j, vector<vector<char>> &board, string &word, bool &found,
           int index = 0) {
    if (outOfBounds(i, j, board) || board[i][j] != word[index])
      return;
    if (index == word.size() - 1) {
      found = true;
      return;
    }
    char temp = board[i][j];
    board[i][j] = '$';
    dfs(i + 1, j, board, word, found, index + 1);
    dfs(i, j + 1, board, word, found, index + 1);
    dfs(i - 1, j, board, word, found, index + 1);
    dfs(i, j - 1, board, word, found, index + 1);
    board[i][j] = temp;
  }
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          bool found = false;
          dfs(i, j, board, word, found);
          if (found)
            return true;
        }
      }
    }
    return false;
  }
};
