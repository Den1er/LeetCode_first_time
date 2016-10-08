203. Remove Linked List Elements
class Solution {
public:
        ListNode* removeElements(ListNode* head, int val) {
                    if(!head)   return NULL;
                    ListNode* dummy = new ListNode(0);
                    dummy->next = head;
                    if(head->val==val)
                    {
                        dummy->next = removeElements(head->next,val);
                    }
                    else
                    {
                        head->next = removeElements(head->next,val);
                    }
                    return dummy->next;
                }
};
