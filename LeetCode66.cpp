142. Linked List Cycle II
class Solution {
public:
        ListNode *detectCycle(ListNode *head) {
                    ListNode* fast = head;
                    ListNode* slow = head;
                    while(fast&&fast->next)
                    {
                        slow = slow->next;
                        fast = fast->next->next;
                        if(slow==fast)
                        {
                            fast = head;
                            while(slow)
                            {
                                if(slow==fast)
                                {
                                    return slow;
                                }
                                else
                                {
                                    slow = slow->next;
                                    fast = fast->next;
                                }
                            }
                        }
                    }
                    return NULL;
                }
};
