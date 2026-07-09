import java.util.Stack;

class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> st = new Stack<>();
        
        for (int i = 0; i < operations.length; i++) {
            if (operations[i].equals("C")) {
                if (!st.isEmpty()) {
                    st.pop();
                }
            } 
            else if (operations[i].equals("D")) {
                if (!st.isEmpty()) {
                    st.push(st.peek() * 2);
                }
            } 
            else if (operations[i].equals("+")) {
                int top1 = st.pop();
                int top2 = st.peek();
                
                st.push(top1);
                st.push(top1 + top2);
            } 
            else {
                st.push(Integer.parseInt(operations[i]));
            }
        }
        
        int totalSum = 0;
        while (!st.isEmpty()) {
            totalSum += st.pop();
        }
        
        return totalSum;
    }
}