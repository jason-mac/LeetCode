// completed
class Solution {
public:
  void rec(vector<int> &nums, vector<int> subset, vector<vector<int>> &res,
           int index) {
    if (index == nums.size() + 1)
      return;
    res.push_back(subset);
    for (int i = index; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      rec(nums, subset, res, i + 1);
      subset.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> subset = {};
    rec(nums, subset, res, 0);
    return res;
  }
};
