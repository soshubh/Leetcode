// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid


class Solution
{
public:
    int numOfWays(int n)
    {

        int kMod = 1'000'000'007;
        long c2 = 6;
        long c3 = 6;

        for (int i = 1; i < n; ++i)
        {
            long nC2 = c2 * 3 + c3 * 2;
            long nC3 = c2 * 2 + c3 * 2;
            c2 = nC2 % kMod;
            c3 = nC3 % kMod;
        }

        return (c2 + c3) % kMod;
    }
};
