2. Add Two Numbers
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
        return helper(l1,l2,0);
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int bit)
    {
        if(!l1&&!l2&&bit==0)
            return NULL;
        else if(!l1&&!l2&&bit!=0)
        {
            ListNode* p = new ListNode(bit);
            return p;
        }
        else{
            ListNode* p = new ListNode(0);
            if(l1&&l2)
            {
                int value = l1->val+l2->val+bit;
                p->val = value%10;
                int b = value/10;
                p->next = helper(l1->next,l2->next,b);
            }
            
            if(!l1)
            {
                int value = l2->val+bit;
                p->val = value%10;
                int b = value/10;
                p->next = helper(NULL,l2->next,b);
            }
            if(!l2)
            {
                int value = l1->val+bit;
                p->val = value%10;
                int b = value/10;
                p->next = helper(l1->next,NULL,b);
            }
            return p;
        }
    }
    
};