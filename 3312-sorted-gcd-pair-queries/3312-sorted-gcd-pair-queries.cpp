

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number in nums
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Calculate exact pair counts for each GCD using inclusion-exclusion
        vector<long long> gcd_counts(max_val + 1, 0);
        
        for (int i = max_val; i >= 1; --i) {
            long long divisible_elements = 0;
            // Count how many numbers are multiples of i
            for (int j = i; j <= max_val; j += i) {
                divisible_elements += count[j];
            }
            
            // Total pairs where GCD is a multiple of i
            long long total_pairs = (divisible_elements * (divisible_elements - 1)) / 2;
            
            // Subtract pairs that have a GCD that is a strict multiple of i
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_counts[j];
            }
            
            gcd_counts[i] = total_pairs;
        }
        
        // Step 3: Compute Prefix Sums of the GCD counts
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + gcd_counts[i];
        }
        
        // Step 4: Answer each query using binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find the first GCD index where the prefix sum strictly exceeds the query index
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            ans.push_back(distance(prefix_sums.begin(), it));
        }
        
        return ans;
    }
};