class Solution {
private:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;  // Cycle detected (currently visiting node again)
        if (state[node] == 2) return false; // Already checked and confirmed safe

        state[node] = 1; // Mark as visiting
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, state)) return true;
        }
        state[node] = 2; // Mark as processed/visited
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) return false;
            }
        }

        return true;
    }
};