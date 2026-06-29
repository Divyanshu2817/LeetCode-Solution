class Solution {
public:
    int search(vector<int>& nums,int l,int h,int target){
        if(l>h){
            return -1;
        }
        int mid=l+(h-l)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return search(nums,l,mid-1,target);
        }
        else{
            return search(nums,mid+1,h,target);
        }
    }
    int search(vector<int>& nums, int target) {
        return search(nums,0,nums.size()-1,target);
    }
};