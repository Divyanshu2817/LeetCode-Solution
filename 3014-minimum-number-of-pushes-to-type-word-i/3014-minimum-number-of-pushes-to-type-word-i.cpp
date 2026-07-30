class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int pushes = 0;
        int multiplier = 1;
        
        while (n > 0) {
            int take = min(n, 8);
            pushes += take * multiplier;
            n -= take;
            multiplier++;
        }
        
        return pushes;
    }
};