class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int left = 0;
    int right = matrix.size() - 1;
    int middle;
    while (left <= right) {
      middle = (right + left) / 2;
      if (matrix[middle][0] <= target &&
          matrix[middle][matrix[0].size() - 1] >= target)
        break;
      if (matrix[middle][matrix[0].size() - 1] > target)
        right = middle - 1;
      if (matrix[middle][0] < target)
        left = middle + 1;
    }
    left = 0;
    right = matrix[0].size() - 1;
    while (left <= right) {
      cout << "mid " << mid << endl;
      if (matrix[middle][mid] == target)
        return true;
      if (matrix[middle][mid] > target)
        right = mid - 1;
      if (matrix[middle][mid] < target)
        left = mid + 1;
    }
    return false;
  }
};
