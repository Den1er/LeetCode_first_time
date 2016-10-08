328. Odd Even Linked List
自己写的
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)   return head;
        ListNode* p = head;
        ListNode* q = head->next->next;
        ListNode* list = head;
        int n = 2;
        while(q)
        {
            
            ListNode* m = head;
            for(int i = 0; i<n-2; ++i)
            {
                m = m->next->next;
            }
            m = m->next;
            ListNode* tmp = q->next;
            q->next = p->next;
            m->next = tmp;
            p->next = q;
            tmp = head;
            for(int i = 0; i<n-1; ++i)
            {
                tmp = tmp->next->next;
            }
            if(tmp->next) tmp = tmp->next->next;
            else break;
            q = tmp;
            
            tmp = head;
            for(int i = 0; i<n-1;++i)
            {
                tmp = tmp->next;
            }
            p = tmp;
            ++n;
        }
        return head;
    }
};