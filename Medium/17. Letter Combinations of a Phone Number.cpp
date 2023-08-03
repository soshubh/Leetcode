// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    vector<string> ans{""};
    vector<string> digitToLetters{"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (auto d : digits) {
      vector<string> temp;
      for (auto s : ans)
        for (auto c : digitToLetters[d - '0'])
          temp.push_back(s + c);
      ans = move(temp);
    }

    return ans;
    }
};
