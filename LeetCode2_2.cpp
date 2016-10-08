24. Swap Nodes in Pairs
class Solution {
public:
        ListNode* swapPairs(ListNode* head) {
                    if(!head||!head->next)   return head;
                    ListNode* dummy = new ListNode(0);
                    dummy->next = head;
                    ListNode* p = head ->next;
                    
                    dummy->next = p;
                    head->next = swapPairs(head->next->next);
                    p->next = head;
                    return dummy->next;
                }
};
