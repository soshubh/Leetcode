// https://leetcode.com/problems/spiral-matrix-ii/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        char p = 'E';
        vector<vector<int>> sm(n, vector<int>(n, 0));
        int num = 1, l = 0, t = 0, r = n - 1, d = n - 1;
        while (l <= r && t <= d)
        {
            if (p == 'E')
            {
                for (int i = l; i <= r; i++)
                    sm[t][i] = num++;
                t++;
                p = 'S';
            }
            else if (p == 'S')
            {
                for (int i = t; i <= d; i++)
                    sm[i][r] = num++;
                r--;
                p = 'W';
            }
            else if (p == 'W')
            {
                for (int i = r; i >= l; i--)
                    sm[d][i] = num++;
                d--;
                p = 'N';
            }
            else
            {
                for (int i = d; i >= t; i--)
                    sm[i][l] = num++;
                l++;
                p = 'E';
            }
        }
        return sm;
    }
};
