// https://leetcode.com/problems/permutations

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> p;
        permute(nums, 0, p);
        return p;
    }

    void permute(vector<int> nums, int s, vector<vector<int>> &p)
    {
        int n = nums.size();
        if (s == n - 1)
            p.push_back(nums);

        else
            for (int i = s; i < n; i++)
                if ((i == s) || (nums[i] != nums[s]))
                {
                    swap(nums[i], nums[s]);
                    permute(nums, s + 1, p);
                }
    }
};
