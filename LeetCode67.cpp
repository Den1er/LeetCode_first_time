61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)    return head;
        int length = 0;
        ListNode* p = head;
        while(p)
        {
            p = p->next;
            ++length;
        }
        k =  k%length;
        if(k==length||k==0)    return head;
        p = head;
        int l = length-1;
        while(l)
        {
            p = p->next;
            --l;
        }
        p->next = head;
        p = head;
        int n = length-k-1;
        while(n)
        {
            p = p->next;
            --n;
        }
        head = p->next;
        p->next =NULL;
        return head;
    }
};