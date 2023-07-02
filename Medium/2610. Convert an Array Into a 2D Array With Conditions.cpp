// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions


class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> a;
        int n = nums.size();
        vector<int> c(n + 1);
        for (int &x : nums)
            c[x]++;

        for (int x = 1; x <= n; ++x)
        {
            int v = c[x];
            for (int j = 0; j < v; ++j)
            {
                if (a.size() <= j)
                    a.push_back({});
                a[j].push_back(x);
            }
        }
        return a;
    }
};
