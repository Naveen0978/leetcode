class MyQueue {
    stack<int> in,out;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
        
    }
    
    int pop() {
        int x;
        if(out.empty() == false)
        {
            x = out.top();
            out.pop();
        }
        else
        {
            while(in.empty() == false)
            {
                out.push(in.top());
                in.pop();
            }
            x = out.top();
            out.pop();
        }
        return x;
    }
    
    int peek() {
        int x;
        if(out.empty() == false)
        {
            x = out.top();
        }
        else
        {
            while(in.empty() == false)
            {
                out.push(in.top());
                in.pop();
            }
            x = out.top();
        }
        return x;
    }
    
    bool empty() {
        if(in.empty() && out.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
