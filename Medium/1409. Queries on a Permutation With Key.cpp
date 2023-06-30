https://leetcode.com/problems/queries-on-a-permutation-with-key


class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> p(m);

        iota(p.begin(), p.end(), 1);

        vector<int> a;

        for (int q : queries)
        {

            int i = find(p.begin(), p.end(), q) - p.begin();
            int t = p[i];
            a.push_back(i);
            p.erase(p.begin() + i);
            p.insert(p.begin(), t);
        }

        return a;
    }
};
