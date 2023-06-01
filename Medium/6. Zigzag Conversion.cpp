//https://leetcode.com/problems/zigzag-conversion/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string a;
        vector<vector<char>> r(numRows);
        int k = 0;
        int d = (numRows == 1) - 1;
        for (const char c : s)
        {
            r[k].push_back(c);
            if (k == 0 || k == numRows - 1)
                d *= -1;
            k += d;
        }
        for (vector<char> &row : r)
            for (char c : row)
                a += c;
        return a;
    }
};
