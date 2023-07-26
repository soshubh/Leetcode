// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution
{
public:
  int minSpeedOnTime(vector<int> &dist, double hour)
  {
    int l = 1, r = 1000000007;

    while (l < r)
    {
      int m = (l + r) >> 1;
      if (check(dist, m, hour))
        r = m;
      else
        l = m + 1;
    }

    return check(dist, l, hour) ? l : -1;
  }

  bool check(vector<int> &dist, int speed, double hour)
  {
    double r = 0;

    for (int i = 0; i < dist.size(); i++)
    {
      double c = (dist[i] * 1.0) / speed;

      r = r + (i == dist.size() - 1 ? c : ceil(c));
    }

    return r <= hour;
  }
};
