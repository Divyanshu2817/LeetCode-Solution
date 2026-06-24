class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char ch: s){
            if(isalpha(ch)){
                result+=ch;
            }
            else if(ch=='*' && result.size()>0){
                result.pop_back();
            }
            else if(ch=='#'&& result.size()>0){
                result+=result;
            }
            else if(ch=='%'&& result.size()>0){
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};