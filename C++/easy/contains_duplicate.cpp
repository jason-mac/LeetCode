class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> f;
    for (int x : nums) {
      if (f.find(x) == f.end()) {
        f.insert(x);
      } else {
        return true;
      }
    }
    return false;
  }
};
