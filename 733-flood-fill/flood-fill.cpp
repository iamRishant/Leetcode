class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int initialColor=grid[sr][sc];
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        grid[sr][sc]=color;

        int delrow[]={1,0,-1,0};
        int delcol[]={0,-1,0,1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int row=it.first;
            int col=it.second;

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==initialColor){
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return grid;
    }
};