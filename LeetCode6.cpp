//Remove Nth Node From End of List
//˫ָ�볣�������ǣ�

//һ��ָ��������Ϊ�ο������Ƴ��ȣ���Ϊѭ��ֹͣ������
//һ��ָ���ӳ����������ܡ���������
//��һ��ָ��������n������Ȼ��򿪵ڶ���ָ�룬����������һ��ָ������ʱ���ڶ���ָ��պ��ܹ�Len-N�����������ҵ��˵�����n������

//ע�⣺����ɾ�������Ƚ����⣬�����ҵ�ǰһ���ڵ����ɾ���¸��ڵ㣬
//����һ��ɾ���������ǻṹ��һ������ڵ���Ϊ��ͷ���Է���ͷ�ڵ㱻ɾ����
//���ϵķ���
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode newhead = new ListNode(-1);  //��ֹͷ��ɾ��
        newhead.next = head;
        ListNode point1 = newhead;
        ListNode point2 = newhead;
        for(;point1 != null;point1 = point1.next,n--)  //point1 ���Ƴ���
        {
            if(n < 0)
                point2 = point2.next;   //point2�ӳ�����
        }
        point2.next = point2.next.next;
        return newhead.next;
    }
}


//�Լ�д�ķ���
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
