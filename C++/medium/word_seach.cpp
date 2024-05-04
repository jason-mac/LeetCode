/*Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.*/
// accepted solution
//

class Solution {
public:
  bool outOfBounds(int i, int j, vector<vector<int>> &grid) {
    return (i == -1 || j == -1 || i == grid.size(); || j == grid[0].size());
  }
  void dfs(int i, int j, vector<vector<int>> &grid, string word, bool &found,
           int index = 0) {
    if (outOfBounds(i, j, grid)) {
      return;
    }
    if (grid[i][j] != word[index]) {
      return;
    }
    if (grid[i][j] == word[index] && index == word.size() - 1) {
      found = true;
      return;
    }
    char temp = grid[i][j];
    grid[i][j] = '$';
    dfs(int i, int j, grid, word, found, index + 1);
    dfs(int i, int j, grid, word, found, index + 1);
    dfs(int i, int j, grid, word, found, index + 1);
    dfs(int i, int j, grid, word, found, index + 1);
    grid[i][j] = temp;
  }
  bool wordSearch(vector<vector<int>> &grid, string word) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == word[0]) {
          bool found = false;
          dfs(i, j, grid, word, found);
          if (found) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
