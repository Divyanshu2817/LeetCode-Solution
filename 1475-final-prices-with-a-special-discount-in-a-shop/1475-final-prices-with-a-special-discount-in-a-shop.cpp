class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st{};
        vector<int> ans{};
        int sz = prices.size();
        for(int i = sz-1; i >= 0; --i)
        {
            while(!st.empty() && st.top() > prices[i])
                st.pop();
            if(st.empty())
                ans.push_back(prices[i]);
            else
                ans.push_back(prices[i]-st.top());
            st.push(prices[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};