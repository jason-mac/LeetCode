/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten
orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh
orange. If this is impossible, return -1.
*/
// lol fuck this, figure it out later lmfaoooo
#include <string>
class Solution {
private:
  vector<int> dy vector<int> dx public : string makeKey(int i, int j) {
    return std::to_string(i) + std::to_string(j);
  }

  int orangesRotting(vector<vector<int>> &grid) {
    int count = 0;
    queue<string> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 2) {
          q.push(makeKey(i, j));
        }
      }
    }
    while (!q.empty()) {
      int size = q.size();
      string entry = q.front();
      for (int i = 0; i < size; i++) {
      }
    }
    return count;
  }
};
