class Solution {
public:
    int dfs(int parent,int node,vector<int> adj[],int &goodNodes){
        int sizeOfSubtree=1;
        unordered_set<int> uniqueSize;

        for(auto it:adj[node]){
            if(it!=parent){
                int currSize=dfs(node,it,adj,goodNodes);
                sizeOfSubtree+=currSize;
                uniqueSize.insert(currSize);
            }
        }
        if(uniqueSize.size()<=1) goodNodes++;

        return sizeOfSubtree;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int goodNodes=0;
        dfs(-1,0,adj,goodNodes);
        return goodNodes;
    }
};