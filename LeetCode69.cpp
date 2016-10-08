147. Insertion Sort List
这是一个我想出来的垃圾解法，效率低得可怕，246ms，大神只用了24ms就解决了这个问题，惭愧
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)    return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* q = head->next;
        int count = 1;
        do
        {
            ListNode* pre = dummy;
            ListNode* curr = dummy->next;
            int d_c = count,d = count+2,da = count;
            while(q->val>curr->val&&d_c)
            {
                pre = pre->next;
                curr = curr->next;
                --d_c;
            }
            if(d_c!=0)
            {
                
                //curr->next = q->next;
                ListNode* p = dummy;
                while(da)
                {
                    p = p->next;
                    --da;
                }
                pre->next = q;
                p->next = q->next;
                q->next = curr;
            }
            q = dummy;
            while(d)
            {
                q = q->next;
                --d;
            }
            ++count;
            //printLink(dummy->next);
        }
        while(q);
        return dummy->next;
    }
};

这个方法减少了很多重复的移动

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};