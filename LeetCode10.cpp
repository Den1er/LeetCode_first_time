//Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = 0;
        if(l1==NULL&&l2==NULL&&flag==0)	return NULL;
        else if(l1==NULL&&l2==NULL&&flag==1)
        {
            ListNode* result = new ListNode(0);
            return result;
        }
        flag = 1;
        if(l1==NULL)     return l2;
            
        else if(l2==NULL)	return l1;

        else
        {
          	
        	if((l1->val+l2->val)<10)
        	{	
        		ListNode* result =new ListNode(l1->val+l2->val);
        	
        		result->next = addTwoNumbers(l1->next,l2->next);
        			return result;
        	}	
        	else
        	{
        		ListNode* result =new ListNode((l1->val+l2->val)%10);
        		ListNode* m = new ListNode(1);
				ListNode* q = addTwoNumbers(l1->next,l2->next);
				q = addTwoNumbers(q,m);
				result->next = q;
					return result;
        	}
    
        }
    }
};