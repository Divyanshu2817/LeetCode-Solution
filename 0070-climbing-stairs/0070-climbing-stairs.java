class Solution {
    public int climbStairs(int n) {
        if (n<=2){
            return n;
        }
        int p2=1;
        int p1=2;
        int current=0;
        for(int i=3;i<=n;i++){
            current=p1+p2;
            p2=p1;
            p1=current;
        }
        return current;
    }
}