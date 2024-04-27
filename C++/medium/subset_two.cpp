// complete
class Solution {
public:
  void rec(vector<int> &nums, vector<vector<int>> &res, vector<int> subset,
           int index = 0) {
    if (index == nums.size() + 1) {

      return;
    }
    res.push_back(subset);
    int i = index;
    while (i < nums.size()) {
      subset.push_back(nums[i]);
      rec(nums, res, subset, i + 1);
      while (i < nums.size() - 1) {
        if (nums[i] == nums[i + 1]) {
          i++;
        } else {
          break;
        }
      }
      subset.pop_back();
      i++;
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    if (nums.size() == 1)
      return {{}, nums};
    vector<vector<int>> res;
    vector<int> subset = {};
    sort(nums.begin(), nums.end());
    rec(nums, res, subset);
    return res;
  }
};
