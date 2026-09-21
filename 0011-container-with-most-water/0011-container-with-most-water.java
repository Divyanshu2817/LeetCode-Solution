class Solution {
    public int maxArea(int[] height) {
        int l=0,r=height.length -1,ans=0;
        while (l<r){
            int cur=r-l;
            int b=Math.min(height[l],height[r]);
            int area=cur*b;
            ans=Math.max(area,ans);
            if (height[l]<height[r]){
                l++;
            }

            else{
                r--;
            }
        }
        return ans;
    }
}