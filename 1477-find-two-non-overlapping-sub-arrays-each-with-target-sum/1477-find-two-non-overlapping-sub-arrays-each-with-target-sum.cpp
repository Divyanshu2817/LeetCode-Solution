class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> min_len(n, INT_MAX);
        
        int left = 0, current_sum = 0;
        int min_single_len = INT_MAX;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            current_sum += arr[right];

            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

            if (current_sum == target) {
                int current_len = right - left + 1;

                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, current_len + min_len[left - 1]);
                }

                min_single_len = min(min_single_len, current_len);
            }

            min_len[right] = min_single_len;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};