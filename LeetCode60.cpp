160. Intersection of Two Linked Lists
class Solution {
public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                    unsigned int lenA = 0,lenB = 0;
                    ListNode* p = headA;
                    while(p)
                    {
                        p = p->next;
                        ++lenA;
                    }
                    p = headB;
                    while(p)
                    {
                        p = p->next;
                        ++lenB;
                    }
                    if(lenA>lenB)
                    {
                        unsigned int dif = lenA-lenB;
                        while(dif)
                        {
                            headA = headA->next;
                            --dif;
                        }
                    }
                    else
                    {
                        unsigned int dif = lenB-lenA;
                        while(dif)
                        {
                            headB = headB->next;
                            --dif;
                        }
                    }
                    while(headA)
                    {
                        if(headA==headB)
                        return headA;
                        headA = headA->next;
                        headB = headB->next;
                    } 
                    return NULL;
                }
};
