// https://leetcode.com/problems/min-stack/

class MinStack
{
public:
    stack<pair<int, int>> stack;
    MinStack()
    {
        //  stack<pair<int, int>> stack;
    }

    void push(int val)
    {
        int mini = val;
        if (!stack.empty())
            mini = min(val, stack.top().second);
        stack.push(make_pair(val, mini));
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }
};
