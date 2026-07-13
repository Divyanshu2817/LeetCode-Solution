class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        // Constructor
    }
    
    void push(int x) {
        q.push(x);
        int s = q.size();
        
        for (int i = 0; i < s - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};