#include <vector>
#include <numeric>

class Solution {
public:
    int subsequencePairCount(std::vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }

        // dp[g1][g2] stores the number of pairs of subsequences 
        // with a current GCD of g1 and g2 respectively.
        std::vector<std::vector<int>> dp(max_val + 1, std::vector<int>(max_val + 1, 0));
        dp[0][0] = 1; // Base case: both subsequences are empty

        for (int x : nums) {
            std::vector<std::vector<int>> next_dp = dp; // Option 1: Skip current element

            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;

                    // Option 2: Add to seq1
                    int ng1 = std::gcd(g1, x);
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;

                    // Option 3: Add to seq2
                    int ng2 = std::gcd(g2, x);
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = std::move(next_dp);
        }

        long long ans = 0;
        // Sum up all pairs where both subsequences have the same non-zero GCD
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};