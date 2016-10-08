class Solution {
public:
        ListNode* deleteDuplicates(ListNode* head) {
                    if(!head||!head->next)   return head;                   
                    ListNode* p = head;
                    ListNode* q = head->next;
                    while(q)
                    {
                        if(p->val==q->val)
                        {
                            p->next = q->next;
                            q = p->next;
                        }
                        else
                        {
                             if(!p->next)    break;
                             q = p->next;
                             p = q;
                             q = q->next;
                        }
                    }
                    return head;
                }
};
