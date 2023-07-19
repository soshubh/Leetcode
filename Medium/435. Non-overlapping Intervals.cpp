// https://leetcode.com/problems/non-overlapping-intervals/

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &i)
  {
    if (i.empty())
      return 0;

    sort(i.begin(), i.end(), [](const auto &a, const auto &b)
         { return a[1] < b[1]; });

    int ans = 0;
    int currentEnd = i[0][1];
    for (int n = 1; n < i.size(); n++)
      if (i[n][0] >= currentEnd)
        currentEnd = i[n][1];
      else
        ans++;

    return ans;
  }
};
