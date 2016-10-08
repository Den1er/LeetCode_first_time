225. Implement Stack using Queues

class Stack {
public:
    queue<int> sta;
    queue<int> tmp;
    int topvalue;
    // Push element x onto stack.
    void push(int x) {
        sta.push(x);
        topvalue = x;
    }
    
    // Removes the element on top of the stack.
    void pop() {
        while(sta.size()>1)
        {
            tmp.push(sta.front());
            sta.pop();
        }
        sta.pop();
        while(tmp.size()>0)
        {
            sta.push(tmp.front());
            tmp.pop();
        }
        topvalue = sta.back();
    }
    
    // Get the top element.
    int top() {
        return topvalue;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return sta.empty();
    }
};