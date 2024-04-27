#include <string>
class Solution {

public:
  bool outOfBounds(int i, int j, vector < vector<int> & grid) {
    return (i == -1 || j == -1 || i == grid.size() || j == grid[0].size());
  }
  string makeKey(int i, int j) { return std::to_string(i) + std::to_string(j); }
  void bfs(int i, int j, vector<vector<int>> &grid) {}
  int orangesRotting(vector<vector<int>> &grid) {
    int time = -1;
    unordered_set<string> visited;
    queue<string> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 2) {
          q.push(pair(i, j));
        }
      }
    }
    int level = 0;
    vector<pair<int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string p = q.front();
        visited.insert(p);
        for (auto direction : directions) {
          string newDirection = makeKey();
          if (outOfBounds(newDirection.first, newDirection.second), grid)
            continue;
          if (visited.find(newDirection) != visited.end())
            continue;
          q.push(newDirection);
          q.pop();
        }
      }
      level++;
    }
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (visited.find(pair(i, j)) != visited.find() || grid[i][j] == 0)
          continue;
        return -1;
      }
    }
    return level;
  }
};
