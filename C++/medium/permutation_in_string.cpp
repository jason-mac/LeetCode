// accepted solution
class Solution {
public:
  bool checkString(string str1, string str2) {
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same,
    // then they cannot be Permutation
    if (n1 != n2)
      return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < n1; i++)
      if (str1[i] != str2[i])
        return false;

    return true;
  }
  int hashString(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
      sum += int(s[i]);
    }
    return sum;
  }
  string getSubstring(string s, int left, int right) {
    string substring = "";
    while (left < right) {
      substring.push_back(s[left]);
      left++;
    }
    return substring;
  }
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    int s1Hash = hashString(s1);
    int s2CurrentHash = 0;
    int left = 0;
    int right = 0;
    while (right != s1.size()) {
      s2CurrentHash += int(s2[right]);
      right++;
    }
    if (s1Hash == s2CurrentHash) {
      if (checkString(s1, getSubstring(s2, left, right))) {
        return true;
      }
    }
    while (right < s2.size()) {
      s2CurrentHash -= int(s2[left]);
      left++;
      right++;
      s2CurrentHash += int(s2[right - 1]);
      if (s1Hash == s2CurrentHash) {
        if (checkString(s1, getSubstring(s2, left, right))) {
          return true;
        }
      }
    }
    return false;
  }
}
