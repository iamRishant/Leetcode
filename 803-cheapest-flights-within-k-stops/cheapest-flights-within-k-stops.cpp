class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // lets first create the graph u->{v,price}
        vector<pair<int,int>> adj[n];

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;//to store stops,node,price
        q.push({0,{src,0}});

        // an array to store the minPrice initially all infinite

        vector<int> minPrice(n,INT_MAX);
        minPrice[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int currStop=it.first;
            int node=it.second.first;
            int price=it.second.second;

            // if(currStop>K) continue;

            for(auto iter: adj[node]){
                int adjNode=iter.first;
                int edgeWeight=iter.second;

                if(price+edgeWeight<minPrice[adjNode]  && currStop<=K){
                    minPrice[adjNode]=price+edgeWeight;
                    q.push({currStop+1,{adjNode, price + edgeWeight}});
                }
            }
        }

        if(minPrice[dst]==INT_MAX) return -1;

        return minPrice[dst];
    }
};