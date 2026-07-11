class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        // Step 2: Find each connected component
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // Step 3: Verify if the component is complete
                int numNodes = component.size();
                bool isComplete = true;

                for (int node : component) {
                    // In a complete component, each node must have exactly (numNodes - 1) neighbors
                    if (adj[node].size() != numNodes - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    completeComponentsCount++;
                }
            }
        }

        return completeComponentsCount;
    }
};