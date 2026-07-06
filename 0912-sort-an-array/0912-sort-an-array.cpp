class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[l + rand() % (r - l + 1)];
        int i = l, j = r;
        while (i <= j) {
            while (nums[i] < pivot) i++;
            while (nums[j] > pivot) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return i;
    }
    
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int idx = partition(nums, l, r);
        quickSort(nums, l, idx - 1);
        quickSort(nums, idx, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        quickSort(nums, 0, n - 1);
        return nums;
    }
};