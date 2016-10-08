234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)   return true;
        unsigned int length = 0;
        ListNode* p = head;
        while(p)
        {
            p = p->next;
            ++length;
        }
        p = head;
        unsigned mid;
        if(length%2==0)
        {
            mid = length/2;
        }
        else
        {
            mid = length/2+1;
        }
        while(mid)
        {
            p = p->next;
            --mid;
        }
        ListNode* q = reverse(p);
        while(q)
        {
            if(head->val!=q->val)
            {
                return false;
            }
            head = head->next;
            q = q->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        if(!head||!head->next) return head;
        ListNode* p = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};