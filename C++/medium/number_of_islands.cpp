// LeetCode 200. Number Of Islands
// Completed and accetped
// O(n*m) time complexity, O(n*m) space complexity
// Possible further improvements, iterative approach instead of recursion to
// achieve in place time complexity
//
class Solution {
public:
  bool outOfBounds(int i, int j, int rowSize, int columnSize) {
    return i == -1 || j == -1 || i == rowSize || j == columnSize;
  }
  void dfs(int i, int j, vector<vector<char>> &grid) {
    if (outOfBounds(i, j, grid.size(), grid[0].size()))
      return;
    if (grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    dfs(i + 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i - 1, j, grid);
    dfs(i, j - 1, grid);
  }
  int numIslands(vector<vector<char>> &grid) {
    unsigned int count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          count++;
          dfs(i, j, grid);
        }
      }
    }
    return count;
  }
};
