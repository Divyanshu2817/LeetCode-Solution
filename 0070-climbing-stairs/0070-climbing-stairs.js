/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n<=2){
            return n;
        }
        var p2=1;
        var p1=2;
        var current=0;
        for(var i=3;i<=n;i++){
            current=p1+p2;
            p2=p1;
            p1=current;
        }
        return current;
    }