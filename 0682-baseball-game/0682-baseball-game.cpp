class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } 
            else if (operations[i] == "D") {
                if (!st.empty()) {
                    st.push(st.top() * 2);
                }
            } 
            else if (operations[i] == "+") {
                
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            } 
            else {
            
                st.push(stoi(operations[i]));
            }
        }
        
        int totalSum = 0;
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }
        
        return totalSum;
    }
};