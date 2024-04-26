// set functions
//  insert, ersase, empty, size
//  solved
//  O(n) space and time complexity, worst case the set contains the entire
//  string
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int length = 1;
    if (s.length() == 0)
      return 0;
    if (s.length() <= 1)
      return length;
    int left = 0;
    int right = 1;
    unordered_set<char> seen;
    seen.insert(s[left]);
    char remove;
    while (right != s.length()) {
      if (seen.count(s[right]) > 0) {
        remove = s[right];
        while (s[left] != remove) {
          seen.erase(s[left]);
          left++;
        }
        left++;
      }
      seen.insert(s[right]);
      length = max(length, right - left + 1);
      right++;
    }
    return length;
  }
};
