// LeetCode 199
//  Using bfs this apporach is O(n) space and time complexity
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};
    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *temp = q.front();
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
        if (i == size - 1)
          res.push_back(temp->val);
        q.pop();
      }
    }
    return res;
  }
};
