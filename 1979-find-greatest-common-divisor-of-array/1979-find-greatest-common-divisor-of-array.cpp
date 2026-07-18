class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        
        // Return the greatest common divisor of the two numbers
        return std::gcd(mn, mx);
    }
};