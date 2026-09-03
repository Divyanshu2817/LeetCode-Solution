class Solution {
    public boolean uniformArray(int[] nums1) {
        int minva=nums1[0];
        boolean hasodd=false;
        for(int x:nums1){
            minva=Math.min(minva,x);
            if(x%2!=0){
                hasodd=true;
            }
        }
        return (minva%2!=0)|| !hasodd;
    }

}