// https://leetcode.com/problems/powx-n

class Solution
{
public:
    double p(double x, int n)
    {
        if (n == 0)
            return 1;

        if (n == 1)
            return x;

        if (n % 2 == 0)
            return p(x * x, n / 2);

        return x * p(x * x, n / 2);
    }

    double myPow(double x, int n)
    {
        if (n < 0)
            return 1.0 / p(x, abs(n));
        return p(x, n);
    }
};
