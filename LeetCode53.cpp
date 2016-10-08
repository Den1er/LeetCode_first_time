141. Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if(!head)   return false;
        ListNode* p = head;
        ListNode* q = head;
        while(q)
        {
            if(!q->next)
            {
                return false;
            }
            else if(q->next->next)
            {
                p = p->next;
                q = q->next->next;
                
            }
            else
            {
                return false;
            }
            if(p==q)    return true;
        }
        return false;
    }
};