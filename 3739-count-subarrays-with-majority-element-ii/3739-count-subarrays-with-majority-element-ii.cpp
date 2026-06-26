class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long result = 0;
        int balance = 0;
        int offset = n;

        vector<int> bit(2 * n + 2, 0);

        auto update = [&](int i) {
            for (i++; i < (int)bit.size(); i += i & (-i))
                bit[i]++;
        };

        auto query = [&](int i) {
            int sum = 0;
            for (i++; i > 0; i -= i & (-i))
                sum += bit[i];
            return sum;
        };

        update(offset);

        for (int i = 0; i < n; i++) {
            balance += (nums[i] == target) ? 1 : -1;
            if (balance + offset - 1 >= 0)
                result += query(balance + offset - 1);
            update(balance + offset);
        }

        return result;
    }
};