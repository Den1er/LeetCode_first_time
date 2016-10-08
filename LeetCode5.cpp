//Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head)
    {

        if(head==NULL)	return NULL;
        ListNode* p = head->next;
        ListNode* q = head;

        	while(p)
        	{
        		if(p->val==q->val)
        			q->next = p->next;
        		else
        			q = p;

        		p = p->next;
			}

        return head;
    }

};

/*第二种做法
class Solution {
public: ListNode *deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL)
    return head;

    ListNode* runner = head;
    while (runner->next != NULL) {
        if (runner->val == runner->next->val) { // duplicate values, make the next as next.next
            runner->next = runner->next->next;
        } else { // otherwise, advance runner to runner.next
            runner = runner->next;
        }
    }

    return head;
}
};
*/
