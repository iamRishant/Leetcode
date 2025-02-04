class Solution {
public:
    void dfs(vector<int> &vis,vector<int> adj[],int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(vis,adj,it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    // adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int> vis(n+1,0);
        vis[0]=1;
        int count=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                count++;
                dfs(vis,adj,i);
            }
        }
        return count;
    }
};