class Solution {
public:
    void solve(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it: adj
        [node]){
            if(!vis[it]) solve(it,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int V=isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    // adj[j].push
                }
            }
        }

        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                solve(i,vis,adj);
            }
        }
        return count;
        
    }
};