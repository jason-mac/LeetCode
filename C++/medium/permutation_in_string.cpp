/*Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 *or false otherwise. In other words, return true if one of s1's permutations is
 *the substring of s2.
 * */
// accepted solution
class Solution {
public:
  // map function

  bool isAnagram(string s1, string s2) {
    std::unordered_map<char, int> count;
    for (auto x : s1) {
      count[x]++;
    }
    for (auto x : s2) {
      count[x]--;
    }
    for (auto x : count) {
      if (x.second != 0) {
        return false;
      }
    }
    return true;
  }
  string getSubstring(string s, int left, int right) {
    string substring = "";
    while (left != right) {
      substring += s[left];
      left++;
    }
    return substring;
  }
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size())
      return false;
    int s1Hash = 0;
    int s2CurrentHash = 0;
    int left = 0;
    int right = 0;
    while (right != s1.size()) {
      s1Hash += int(s1[right]);
      s2CurrentHash += int(s2[right]);
      right++;
    }
    while (right < s2.size()) {
      if (s1Hash == s2CurrentHash) {
        if (isAnagram(s1, getSubstring(s2, left, right))) {
          return true;
        }
      }
      s2CurrentHash -= int(s2[left]);
      left++;
      s2CurrentHash += int(s2[right]);
      right++;
    }
    if (s1Hash == s2CurrentHash) {
      if (isAnagram(s1, getSubstring(s2, left, right))) {
        return true;
      }
    }
    return false;
  }
};
