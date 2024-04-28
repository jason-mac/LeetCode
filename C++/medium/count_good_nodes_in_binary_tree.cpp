// accepted solution
class Solution {
public:
  void rec(TreeNode *root, int previousMax, int &count) {
    if (!root)
      return;
    if (previousMax <= root->val)
      count++;
    previousMax = max(previousMax, root->val);
    rec(root->left, previousMax, count);
    rec(root->right, previousMax, count);
  }
  int goodNodes(TreeNode *root) {
    int count = 0;
    int currentMax = root->val;
    rec(root, currentMax, count);
    return count;
  }
};
