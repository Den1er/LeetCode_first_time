//Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int flag)
    {
        if(!l1 && !l2 )
        {
            if(flag == 0)
                return NULL;
            else
            {
                ListNode* res = new ListNode(1);
                return res;
            }
        }
        else if(!l1 && l2 || !l2 && l1)
        {
            ListNode* tmp = l1 == NULL ? l2 : l1;
            ListNode* tmp2 = l2 == NULL ? l2 : l1;
            if(tmp->val + flag > 9)
            {
                ListNode* res = new ListNode((tmp->val + flag) % 10);
                res->next = helper(tmp->next, NULL, 1);
                return res;
            }
            else
            {
                ListNode* res = new ListNode(tmp->val + flag);
                res->next = helper(tmp->next, NULL, 0);
                return res;
            }
        }
        else
        {
            if(l1->val + l2->val + flag > 9)
            {
                ListNode* res = new ListNode((l1->val + l2->val + flag) % 10);
                res->next = helper(l1->next, l2->next, 1);
                return res;
            }
            else
            {
                ListNode* res = new ListNode(l1->val + l2->val + flag);
                res->next = helper(l1->next, l2->next, 0);
                return res;
            }
        }
    }
};