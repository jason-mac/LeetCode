class Solution {
public:
  int characterReplacement(string s, int k) {
    int result = 0;
    int left = 0;
    int right = 0;
    int windowLength = 0;
    pair<int, int> mostFrequent = {0, 0};
    std::unordered_map<int, int> count;
    for (int i = 0; i < 26; i++) {
      count[int('A') + 1] = 0;
    }
    while (right < s.size()) {
      int rightCharacter = int(s[right]);
      windowLength = right - left + 1;
      count[rightCharacter] += 1;
      if (count[rightCharacter] > mostFrequent.second) {
        mostFrequent = pair<int, int>(rightCharacter, count[rightCharacter]);
      }
      if (windowLength - count[mostFrequent.first] <= k) {
        result = max(result, windowLength);
      } else {
        count[int(s[left])] -= 1;
        left++;
      }
      right++;
    }
    return result;
  }
};
