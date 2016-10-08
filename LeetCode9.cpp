//Swap Nodes in Pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         if(head==NULL||head->next==NULL)
        	return head;
        int tmp = head->val;
        head->val = head->next->val;
        head->next->val = tmp;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
};