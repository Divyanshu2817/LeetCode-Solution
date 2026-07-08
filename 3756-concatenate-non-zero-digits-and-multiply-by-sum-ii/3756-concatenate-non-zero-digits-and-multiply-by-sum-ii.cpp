#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // Filter out non-zero digits and track their original string indices
        vector<int> digits;
        vector<int> orig_idx;
        
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                orig_idx.push_back(i);
            }
        }
        
        int n = digits.size();
        if (n == 0) {
            return vector<int>(queries.size(), 0);
        }
        
        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // Prefix sums of digits
        vector<long long> pref_sum(n + 1, 0);
        // Prefix rolling value representation of concatenated digits
        vector<long long> pref_val(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            pref_sum[i + 1] = pref_sum[i] + digits[i];
            pref_val[i + 1] = (pref_val[i] * 10 + digits[i]) % MOD;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int L = q[0], R = q[1];
            
            // Find the first non-zero digit index >= L
            int idx1 = lower_bound(orig_idx.begin(), orig_idx.end(), L) - orig_idx.begin();
            // Find the last non-zero digit index <= R
            int idx2 = upper_bound(orig_idx.begin(), orig_idx.end(), R) - orig_idx.begin() - 1;
            
            if (idx1 > idx2) {
                ans.push_back(0);
                continue;
            }
            
            // 1-based indexing for prefixes
            int len = idx2 - idx1 + 1;
            
            // Extract the value of x modulo 10^9 + 7
            long long x = (pref_val[idx2 + 1] - (pref_val[idx1] * pow10[len]) % MOD + MOD) % MOD;
            
            // Extract the sum of digits
            long long sum = pref_sum[idx2 + 1] - pref_sum[idx1];
            
            long long current_ans = (x * (sum % MOD)) % MOD;
            ans.push_back(current_ans);
        }
        
        return ans;
    }
};