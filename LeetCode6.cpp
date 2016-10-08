//Remove Nth Node From End of List
//双指针常用做法是：

//一个指针用来作为参考，控制长度（作为循环停止条件）
//一个指针延迟启动用来跑“倒数”。
//第一个指针先运行n个数，然后打开第二个指针，这样，当第一个指针跑完时，第二个指针刚好跑过Len-N数，这样就找到了倒数第n个数。

//注意：由于删除操作比较特殊，必须找到前一个节点才能删除下个节点，
//所以一般删除操作我们会构造一个虚拟节点作为开头，以防开头节点被删除。
//网上的方法
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode newhead = new ListNode(-1);  //防止头被删除
        newhead.next = head;
        ListNode point1 = newhead;
        ListNode point2 = newhead;
        for(;point1 != null;point1 = point1.next,n--)  //point1 控制长度
        {
            if(n < 0)
                point2 = point2.next;   //point2延迟启动
        }
        point2.next = point2.next.next;
        return newhead.next;
    }
}


//自己写的方法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* front = new ListNode(0);
        front->next = head;
        int count=0,downcount;
        while(p)
        {
        	p = p->next;
        	count++;
        }
        downcount = count-n+1;
        ListNode* q = front;
        for(int i = 1;i<downcount;i++)
        {
        	q = q->next;
        }
        q->next = q->next->next;
        head = front->next;
        delete front;
        return head;
    }
