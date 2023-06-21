// https://leetcode.com/problems/swap-nodes-in-pairs

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        auto newHead = new ListNode(-1);
        newHead->next = head;
        auto node = newHead;
        while (node != NULL & node->next != NULL && node->next->next != NULL)
        {
            auto first = node;
            auto second = node->next;
            auto third = node->next->next;
            first->next = third;
            second->next = third->next;
            third->next = second;
            node = second;
        }
        return newHead->next;
    }
};
