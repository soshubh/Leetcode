// https://leetcode.com/problems/find-peak-element

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + r >> 1;
            if (nums[m] > nums[m + 1])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
