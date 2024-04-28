/*
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in any
 * order. mapping of digits to letters (just like on the telephone buttons) is
 * given below. Note that 1 does not map to any letters.
 *
 */
class Solution {
public:
  vector<char> letters(char n) {
    if (n == '2') {
      return {'a', 'b', 'c'};
    }
    if (n == '3') {
      return {'d', 'e', 'f'};
    }
    if (n == '4') {
      return {'g', 'h', 'i'};
    }
    if (n == '5') {
      return {'j', 'k', 'l'};
    }
    if (n == '6') {
      return {'m', 'n', 'o'};
    }
    if (n == '7') {
      return {'p', 'q', 'r', 's'};
    }
    if (n == '8') {
      return {'t', 'u', 'v'};
    }
    if (n == '9') {
      return {'w', 'x', 'y', 'z'};
    }
    return {};
  }
  void rec(string combination, vector<vector<char>> &map, vector<string> &res,
           int index = 0) {
    if (combination.size() == map.size()) {
      res.push_back(combination);
      return;
    }
    for (int i = 0; i < map[index].size(); i++) {
      combination += map[index][i];
      rec(combination, map, res, index + 1);
      combination.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits == "")
      return {};
    string combination = "";
    vector<vector<char>> map;
    vector<string> res;
    for (int i = 0; i < digits.size(); i++) {
      map.push_back(letters(digits[i]));
    }
    rec(combination, map, res);
    return res;
  }
}
