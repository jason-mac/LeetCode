// complete
class Solution {
public:
  int sum(vector<int> &combination) {
    int sum = 0;
    for (int val : combination) {
      sum += val;
    }
    return sum;
  }
  void rec(vector<int> &candidates, vector<vector<int>> &result,
           vector<int> combination, int target, int index = 0) {
    if (sum(combination) > target)
      return;
    if (sum(combination) == target) {
      result.push_back(combination);
      return;
    }
    int i = index;
    while (i < candidates.size()) {
      combination.push_back(candidates[i]);
      rec(candidates, result, combination, target, i + 1);
      while (i < candidates.size() - 1) {
        if (candidates[i] == candidates[i + 1]) {
          i++;
        } else {
          break;
        }
      }
      combination.pop_back();
      i++;
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    rec(candidates, result, combination, target);
    return result;
  }
};
