class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Remove duplicates from nums
        vector<int> u = nums;
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
        
        // Step 1: Compute all unique pairwise XOR values (a ^ b)
        unordered_set<int> pairs;
        for (int i = 0; i < u.size(); ++i) {
            for (int j = i; j < u.size(); ++j) {
                pairs.insert(u[i] ^ u[j]);
            }
        }
        
        // Step 2: Compute all unique triplet XOR values (a ^ b ^ c)
        unordered_set<int> triplets;
        for (int p : pairs) {
            for (int x : u) {
                triplets.insert(p ^ x);
            }
        }
        
        return triplets.size();
    }
};