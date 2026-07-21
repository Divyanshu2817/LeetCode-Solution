class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initial_ones = 0;
        for (char c : s) {
            if (c == '1') initial_ones++;
        }

        // Augment the string as per problem statement
        string t = "1" + s + "1";

        // Perform Run-Length Encoding (RLE) on t
        vector<pair<char, int>> blocks;
        for (char c : t) {
            if (!blocks.empty() && blocks.back().first == c) {
                blocks.back().second++;
            } else {
                blocks.push_back({c, 1});
            }
        }

        int max_delta = 0;

        // Iterate over blocks to find any inner '1' block
        for (size_t i = 1; i + 1 < blocks.size(); ++i) {
            if (blocks[i].first == '1') {
                // Surrounded by blocks[i-1] ('0's) and blocks[i+1] ('0's)
                int delta = blocks[i - 1].second + blocks[i + 1].second;
                max_delta = max(max_delta, delta);
            }
        }

        return initial_ones + max_delta;
    }
};