class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        
        // 1. Create a copy of the array to sort
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // 2. Create a map to store unique elements and their ranks
        unordered_map<int, int> rankMap; // unordered_map is faster (O(1) average lookups)
        int rank = 1;
        
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        // 3. Replace each element of the ORIGINAL array with its rank
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};