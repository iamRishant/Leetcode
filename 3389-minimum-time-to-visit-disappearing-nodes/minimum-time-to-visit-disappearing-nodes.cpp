class Solution {
public:
    vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S,vector<int> &disappear,vector<int> &vis)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(vis[node] || dis>=disappear[node]) continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                    vis[node]=1;
                }
            }
            
        }
            return dist;
    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<pair<int,int>> adjList[n];
        vector<int> vis(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adjList[u].push_back({v,cost});
            adjList[v].push_back({u,cost});
        }


        vector<int> ans=dijkstra(n,adjList,0,disappear,vis);


        
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=disappear[i]) ans[i]=-1;
        }
        return ans;
    }
};