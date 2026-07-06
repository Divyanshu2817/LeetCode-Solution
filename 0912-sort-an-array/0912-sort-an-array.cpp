class Solution {
public:
    void merge(vector<int>& nums,int l,int mid,int r){
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int> left(n1),right(n2);
        for(int i=0;i<n1;i++){
            left[i]=nums[l+i];
        }
        for(int i=0;i<n2;i++){
            right[i]=nums[mid+1+i];
        }
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) nums[k++] = left[i++];
            else nums[k++] = right[j++];
        }
        while (i < n1) nums[k++] = left[i++];
        while (j < n2) nums[k++] = right[j++];
    }
    
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums;
        mergeSort(nums,0,n-1);
        return nums;
    }
};