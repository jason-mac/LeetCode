// LeetCode 124. Binary Tree Maximum Path Sum
// to be honest, no clue what's happening in here that I wrote
// O(n) time complexity, O(log(n)) space complexity
// possible improvements, iterative approach over recursion

class Solution {
private:
  int rec(TreeNode *current, int &currentMax) {
    if (!current)
      return -1001;
    int left = rec(current->left, currentMax);
    int right = rec(current->right, currentMax);
    if (left == -1001 && right == -1001) {
      if (current->val > currentMax)
        currentMax = current->val;
      return current->val;
    }
    if (current->val > currentMax)
      currentMax = current->val;
    if (left + right + current->val > currentMax)
      currentMax = left + right + current->val;
    if (left > currentMax)
      currentMax = left;
    if (right > currentMax)
      currentMax = right;
    if (left + current->val > currentMax)
      currentMax = left + current->val;
    if (right + current->val > currentMax)
      currentMax = right + current->val;
    return max(max(left, right) + current->val, current->val);
  }

public:
  int maxPathSum(TreeNode *root) {
    int max = root->val;
    rec(root, max);
    return max;
  }
};
