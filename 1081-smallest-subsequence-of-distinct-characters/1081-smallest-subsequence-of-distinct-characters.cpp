class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        string result = "";
        
        // Count frequencies of each character
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (char c : s) {
            // Decrement the remaining count for the current character
            count[c - 'a']--;
            
            // If the character is already in our result, skip it
            if (visited[c - 'a']) {
                continue;
            }
            
            // Pop characters from the result if they are lexicographically larger
            // than the current character and appear again later
            while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add the current character to the result and mark it visited
            result.push_back(c);
            visited[c - 'a'] = true;
        }
        
        return result;
    }
};