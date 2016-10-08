232. Implement Queue using Stacks
class Queue {
public:
    stack<int> s;
    stack<int> tmp;
    int firstvalue;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        while(s.size()>1)
        {
            tmp.push(s.top());
            s.pop();
        }
        firstvalue = s.top();
        s.pop();
        while(tmp.size()>0)
        {
            s.push(tmp.top());
            tmp.pop();
        }
    }
    
    // Get the front element.
    int peek(void) {
        tmp = s;
        while(tmp.size()>1)
        {
            tmp.pop();
        }
        firstvalue = tmp.top();
        tmp.pop();
        return firstvalue;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};