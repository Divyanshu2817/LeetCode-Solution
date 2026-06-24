class Solution {
public:
    char findTheDifference(string s, string t) {

        int sum_s = 0;
        for(char &ch:s){
            sum_s += ch;
        }
        int sum_tt = 0;
        for(char &ch:t){
            sum_tt += ch;
        }
        return (char)(sum_tt - sum_s);
    }
};
