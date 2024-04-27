// copmleted, kind of a jank solution though
class Solution {
public:
  void rec(vector<int> &nums, vector<vector<int>> &res, vector<int> permutation,
           unordered_set<int> seen) {
    if (permutation.size() == nums.size()) {
      res.push_back(permutation);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (seen.find(i) != seen.end())
        continue;
      seen.insert(i);
      permutation.push_back(nums[i]);
      rec(nums, res, permutation, seen);
      seen.erase(i);
      permutation.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res = {};
    vector<int> permutation = {};
    unordered_set<int> seen;
    rec(nums, res, permutation, seen);
    return res;
  }
};
