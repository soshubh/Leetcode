// https://leetcode.com/problems/add-two-numbers-ii


class Solution
{
    ListNode *reverse(ListNode *head)
    {
        auto curr = head;
        ListNode *prev = NULL;
        while (curr != NULL)
        {

            auto next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        l1 = reverse(l1);
        l2 = reverse(l2);

        int car = 0;
        auto temp = new ListNode(-1);
        auto curr = temp;

        while (l1 != NULL || l2 != NULL)
        {

            int a = l1 == NULL ? 0 : l1->val;
            int b = l2 == NULL ? 0 : l2->val;
            int c = (a + b + car) % 10;

            curr->next = new ListNode(c);

            car = (a + b + car) / 10;

            curr = curr->next;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        if (car > 0)
            curr->next = new ListNode(car);

        return reverse(temp->next);
    }
};
