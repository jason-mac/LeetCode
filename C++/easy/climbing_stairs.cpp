// accepted solution
class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    std::unordered_map<int, int> _map;
    _map[n - 1] = 1;
    _map[n - 2] = 2;
    int backsteps = n - 3;
    while (backsteps != -1) {
      _map[backsteps] = _map[backsteps + 1] + _map[backsteps + 2];
      backsteps--;
    }
    return _map[0];
  }
}
