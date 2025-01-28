class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &color,int currentColor,int node){
        if(color[node]!=0){
            if(color[node]==currentColor) return true;
            else return false;
        }
        color[node]=currentColor;

        for(auto it: graph[node]){
            
                if(dfs(graph,color,-1*currentColor,it)==false) return false;
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //bipartite graph means if we can color the whole graph with 2 colors 
        // whereas no two adjacent have same color

        int n=graph.size();
        vector<int> color(n,0);

        for(int i=0;i<n;i++){
            if(color[i]==0){
                // coloring with 1 and -1
                if(dfs(graph,color,1,i)==false) return false;
            }
        }
        return true;
    }
};