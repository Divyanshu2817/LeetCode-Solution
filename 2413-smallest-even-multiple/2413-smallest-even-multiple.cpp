class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans;
        while(n>0){
            if(n%2==0){
                ans=n;
                return ans;
            }
            else{
                ans=n*2;
                return ans;
            }
        }
        return ans;
    }
};