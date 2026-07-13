class MyQueue {
private:
    stack<int> stk_in;
    stack<int> stk_out;
    void shiftStacks() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    void push(int x) {
        stk_in.push(x);
    }
    
    int pop() {
        shiftStacks();
        int frontElement = stk_out.top();
        stk_out.pop();
        return frontElement;
    }
    
    int peek() {
        shiftStacks();
        return stk_out.top();
    }
    
    bool empty() {
        return stk_in.empty() && stk_out.empty();
    }
};