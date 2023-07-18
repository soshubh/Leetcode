// https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    int k = 1'000'000'007;
    
    int countGoodNumbers(long long n) {
        return m(4 * 5, n / 2) * (n & 1 ? 5 : 1) % k;
    }

    long m(long x, long n) {
        
        if (n == 0)
          return 1;
        
        if (n & 1)
          return x * m(x, n - 1) % k;

       return m(x * x % k, n / 2);
    }
};
