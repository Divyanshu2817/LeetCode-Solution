class Solution {
public:
vector<vector<int>> ans;
    void  sol(int idx,vector<int>& nums,vector<int>& temp){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            sol(i+1,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        sol(0, nums, temp);
        return ans;
    }
};