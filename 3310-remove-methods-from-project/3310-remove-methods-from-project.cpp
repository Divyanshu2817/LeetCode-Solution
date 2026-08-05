class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        std::vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        std::vector<bool> is_suspicious(n, false);
        std::queue<int> q;
        
        q.push(k);
        is_suspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : adj[curr]) {
                if (!is_suspicious[neighbor]) {
                    is_suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!is_suspicious[u] && is_suspicious[v]) {
                can_remove = false;
                break;
            }
        }

        // Step 4: Construct result
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!can_remove || !is_suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};