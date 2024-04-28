// solution accepted
class Solution {
public:
  bool outOfBounds(int i, int j, vector<vector<int>> &grid) {
    return (i == -1 || j == -1 || i == grid.size() || j == grid[0].size());
  }
  void dfs(int i, int j, vector<vector<int>> &grid, int &area) {
    if (outOfBounds(i, j, grid)) {
      return;
    }
    if (grid[i][j] != 1) {
      return;
    }
    grid[i][j] = 0;
    area += 1;
    dfs(i + 1, j, grid, area);
    dfs(i, j + 1, grid, area);
    dfs(i - 1, j, grid, area);
    dfs(i, j - 1, grid, area);
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int currentMaxArea = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          int area = 0;
          dfs(i, j, grid, area);
          currentMaxArea = max(currentMaxArea, area);
        }
      }
    }
    return currentMaxArea;
  }
};
