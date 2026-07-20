class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        // Effective shifts needed
        k = k % totalElements;
        
        // Create a result grid of the same dimensions
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Find the flattened 1D index and calculate the shifted position
                int oldLinearIndex = i * n + j;
                int newLinearIndex = (oldLinearIndex + k) % totalElements;
                
                // Convert back to 2D coordinates
                int newRow = newLinearIndex / n;
                int newCol = newLinearIndex % n;
                
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};