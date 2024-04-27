class Solution {
public:
  int characterReplacement(string s, int k) {
    int res = 1 + k;
    if (s.length() == 1)
      return 1;
    int left = 0;
    int count = 0;
    int right = 1;
    char checker;
    while (left != s.length() - k) {
      count = 0;
      checker = s[left];
      while (count != k && right != s.length()) {
        if (s[right] != checker)
          count++;
        right++;
      }
      while (s[right] == checker && right != s.length())
        right++;
      res = max(res, right - left);
      left++;
      right = left + 1;
    }
    left = s.length() - 1;
    right = s.length() - 2;
    while (left != k) {
      count = 0;
      checker = s[left];
      while (count != k && right != -1) {
        if (s[right] != checker)
          count++;
        right--;
      }
      while (s[right] == checker && right - 1)
        right--;
      res = max(res, left - right);
      left--;
      right = left - 1;
    }
    return res;
  }
};
