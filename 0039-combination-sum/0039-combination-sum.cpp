class Solution {
private:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        if (index == candidates.size() || target < 0) {
            return;
        }

        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, result); 
            current.pop_back(); 
        }

        findCombinations(index + 1, target, candidates, current, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};