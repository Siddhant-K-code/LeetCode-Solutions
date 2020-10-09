/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1, *p2 = l2, *fa;
        int in = 0;
        while (p1 && p2)
        {
            p1->val += p2->val + in;
            in = 0;
            if (p1->val > 9)
            {
                p1->val %= 10;
                in = 1;
            }
            fa = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2)
        {
            fa->next = p2;
            p1 = p2;
        }
        while (in)
        {
            if (p1 == NULL)
            {
                p1 = new ListNode(0);
                fa->next = p1;
            }
            p1->val += in;
            in = 0;
            if (p1->val > 9)
            {
                p1->val %= 10;
                in = 1;
            }
            fa = p1;
            p1 = p1->next;
        }
        return l1;
    }
};