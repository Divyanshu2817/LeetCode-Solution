class Solution {
public:
    int fib(int n,int a,int b){
        if(n==0){
            return a;
        }
        return fib(n-1,b,a+b);
    }
    int fib(int n) {
        
        return fib(n,0,1);
    }
};