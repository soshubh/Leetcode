// https://leetcode.com/problems/maximum-running-time-of-n-computers

class Solution
{
public:
  long long maxRunTime(int n, vector<int> &batteries)
  {

    long long s = accumulate(batteries.begin(), batteries.end(), 0LL);
    sort(batteries.begin(), batteries.end());

    while (batteries.back() > s / n)
    {
      s -= batteries.back();
      batteries.pop_back();
      n--;
    }

    return s / n;
  }
};
