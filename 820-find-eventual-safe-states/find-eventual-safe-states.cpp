class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& safe, vector<vector<int>>& graph) {
        // If the node is already visited, check if it's marked as unsafe
        if (vis[node] != 0) {
            return vis[node] == 2;  // 2 means it's safe
        }

        // Mark the node as visiting
        vis[node] = 1;
        for (auto it : graph[node]) {
            // If the neighboring node is not safe, mark the current node as unsafe
            if (!dfs(it, vis, safe, graph)) {
                return false;
            }
        }

        // Mark the node as safe
        vis[node] = 2;
        safe[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);  // 0: unvisited, 1: visiting, 2: safe
        vector<int> safe(n, 0);  // Mark nodes that are safe
        vector<int> ans;

        // Run dfs for each node to determine if it's safe
        for (int i = 0; i < n; i++) {
            dfs(i, vis, safe, graph);
        }

        // Collect all the safe nodes
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
