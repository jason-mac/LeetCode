// accepted SOlution
class Solution {
public:
  int minCostClimbingStairs(vector<int> &costs) {
    unordered_map<int, int> _map;

    int back = costs.size() - 3;
    _map[back - 1] = costs[costs.size() - 1];
    _map[back - 2] = costs[costs.size() - 2];

    while (back != -1) {
      _map[back] = costs[back] + min(_map[back + 1], _map[back + 2]);
    }
    return min(_map[0], _map[1]);
  }
};
