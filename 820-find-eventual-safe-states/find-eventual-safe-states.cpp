class Solution {
public:
    bool isCycle(int node, vector<int> &vis,vector<int> &pathVis,vector<vector<int>> &graph){
        vis[node]=2;
        // pathVis[node]=1;

        for(auto &it: graph[node]){
            if(!vis[it]){
                if(isCycle(it,vis,pathVis,graph)) return true;
            }
            else if(vis[it]==2) return true;
        }

        vis[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0),pathVis(n,0);
        vector<int> ans;

        // using single array to detect cycle

        for(int i=0;i<n;i++){
            if(isCycle(i,vis,pathVis,graph)) continue;
            else ans.push_back(i);
        }
        return ans;
    }
};