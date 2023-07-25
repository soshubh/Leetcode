// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int l = 0, r = arr.size() - 1;

    while (l < r)
    {
      int m = (l + r) / 2;
      if (arr[m] >= arr[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
