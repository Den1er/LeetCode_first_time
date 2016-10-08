19. Remove Nth Node From End of List
二刷
class Solution {
public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
                    ListNode* dummy;
                    dummy->next = head;
                    ListNode* p = dummy;
                    ListNode* q = p;
                    while(n)
                    {
                        q = q->next;
                        --n;
                    }
                    while(q->next)
                    {
                        p = p->next;
                        q = q->next;
                    }
                    p->next = p->next->next;
                    return dummy->next;
                }
};
