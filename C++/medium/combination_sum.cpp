// accepted
class Solution {
public:
  int sum(vector<int> &vec) {
    int sum = 0;
    for (int x : vec) {
      sum += x;
    }
    return sum;
  }
  void rec(vector<int> &candidates, vector<int> combination,
           vector<vector<int>> &res, int target, int index) {
    if (index == candidates.size())
      return;
    if (sum(combination) > target)
      return;
    if (sum(combination) == target) {
      res.push_back(combination);
      return;
    }
    combination.push_back(candidates[index]);
    rec(candidates, combination, res, target, index);
    combination.pop_back();
    rec(candidates, combination, res, target, index + 1);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> combination;
    sort(combination.begin(), combination.end());
    rec(candidates, combination, res, target, 0);
    return res;
  }
};
