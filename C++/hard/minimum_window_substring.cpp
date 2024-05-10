#include <unordered_map>
class Solution {
public:
  string getSubstring(int left, int right, string s) {
    string substring = "";
    while (left < right) {
      substring.push_back(s[left]);
      left++;
    }
    return substring;
  }
  string substring;
  string minWindow(string s, string t) {
    string result;
    int left = 0;
    int right = 0;
    int bestLeft;
    int bestRight;
    int minLength = s.size();
    int conditionsMet = 0;
    int windowLength = right - left + 1;
    std::unordered_map<int, int> countSubstring;
    std::unordered_map<char, int> countT;
    for (int i = 0; i < t.size(); i++) {
      if (countT[t[i]] == countT.end()) {
        countT[t[i]] = 1;
      } else {
        countT[t[i]] += 1;
      }
    }
    for (auto x : countT) {
      countSubstring[x.first] = 0;
    }
    const int condidionsRequired = countT.size();
    while (right < s.size()) {
      if (countT.count(s[right])) {
        countSubstring(s[right]) += 1;
        if (countT[s[right]] == countSubstring[s[right]]) {
          conditionsMet++;
        }
      }
      while(conditionsMet == conditionsRequired) {
        if (right - left + 1 < minLength) {
          bestLeft = left;
          bestRight = right;
        }
          if (countT.count(s[left])) {
            countSubstring[s[left]] -= 1;
            if (countSubstring[s[left]] < countT[s[left]]) {
              conditionsMet -= 1;
            }
          }
          left++;
        }
      right++;
    }
    return getSubstring(bestLeft, bestRight, s);
  }
};
