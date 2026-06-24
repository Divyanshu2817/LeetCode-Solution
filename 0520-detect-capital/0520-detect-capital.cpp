class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        for (char ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                capitalCount++;
            }
        }
        if (capitalCount == word.length()) {
            return true;
        }
        
        if (capitalCount == 0) {
            return true;
        }
        
        if (capitalCount == 1 && (word[0] >= 'A' && word[0] <= 'Z')) {
            return true;
        }
        return false;
    }
};