class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        vector<int> stack;
        int max_area = 0;
        for (int i = 0; i < n ; ++i) {
            while (!stack.empty() && heights[i] < heights[stack.back()]) {
                int h = heights[stack.back()];
                stack.pop_back();
                int l = stack.empty() ? i : i - stack.back() - 1;
                max_area = max(max_area, h * l);
            }
            stack.push_back(i);
        }
        return max_area;
    }
};