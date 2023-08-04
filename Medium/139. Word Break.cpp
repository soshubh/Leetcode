// https://leetcode.com/problems/word-break
class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    bool r[s.length() + 1];
    string t = "*" + s;
    r[0] = true;

    for (int i = 1; i < t.length(); i++)
    {
      for (int k = 0; k < i; k++)
      {
        r[i] = r[k] && (find(wordDict.begin(), wordDict.end(), s.substr(k, i - k)) != wordDict.end());
        if (r[i])
          break;
      }
    }
    return r[s.length()];
  }
};
