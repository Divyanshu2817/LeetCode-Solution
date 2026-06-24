constexpr int MOD = 1e9 + 7;
static int dp[2000];
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int range = r - l + 1;
        const tuple<int,int,int> dir[2] = {{0 , range , 1} , {range - 1 , -1 , -1}};
        fill(dp , dp + range , 1);
        for(int i = 1; i < n; ++i){
            int sum = 0;
            const auto& [start , end , step] = dir[i & 1];
            for(int j = start; j != end; j += step){
                const int temp = dp[j];
                dp[j] = sum;
                sum = (sum + temp) % MOD;
            }
        }
        return (reduce(dp , dp + range , 0LL) << 1) % MOD;
    }
};