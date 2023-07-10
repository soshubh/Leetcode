// https://leetcode.com/problems/partition-list

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode beforeHead(0);
        ListNode afterHead(0);
        auto before = &beforeHead;
        auto after = &afterHead;

        for (; head; head = head->next)
            if (head->val < x)
            {
                before->next = head;
                before = head;
            }
            else
            {
                after->next = head;
                after = head;
            }
        after->next = NULL;
        before->next = afterHead.next;

        return beforeHead.next;
    }
};
