class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        struct BIT {
            vector<int> tree;
            int n;
            BIT(int n) : n(n), tree(n + 1, 0) {}
            void update(int i) {
                for (i++; i <= n; i += i & -i) tree[i]++;
            }
            int query(int i) {
                int s = 0;
                for (i++; i > 0; i -= i & -i) s += tree[i];
                return s;
            }
        };

        int n = nums.size();
        int offset = n;
        BIT bit(2 * n + 1);

        int prefixSum = 0, result = 0;
        bit.update(offset);

        for (int& num : nums) {
            prefixSum += (num == target) ? 1 : -1;
            int idx = prefixSum - 1 + offset;
            if (idx >= 0) result += bit.query(idx);
            bit.update(prefixSum + offset);
        }

        return result;
    }
};