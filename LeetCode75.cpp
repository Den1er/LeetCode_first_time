143. Reorder List
调BUG调了很久，觉得自己还是很不扎实，对链表的基本操作还没得门道呢，一定要记住看函数返回值，记得保存要修改的但是还有作用的变量
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
    void reorderList(ListNode* head) {
        if(!head||!head->next)  return;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy,*fast = dummy;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverse(slow->next);
        slow->next = NULL;
        
        slow = head;
        while(fast)
        {
            ListNode* tmp = slow->next;
            ListNode* temp = fast->next;
            slow->next = fast;
            slow = tmp;
            fast->next = tmp;
            fast = temp;
            
        }
        
    }
    ListNode* reverse(ListNode* head)
    {
        if(!head||!head->next)  return head;
        ListNode* p = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};