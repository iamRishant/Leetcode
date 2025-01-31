class Solution {
public:
    int n,m;
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,int delrow[],int delcol[]){
        
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis,delrow,delcol);
            }
        }

    }
    void dfs2(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,int delrow[],int delcol[],int &ans){
        
        if(vis[row][col]==0){
            ans=false;
        }
        vis[row][col]=2;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]<2 && grid[nrow][ncol]==1){
                dfs2(nrow,ncol,grid,vis,delrow,delcol,ans);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();

        vector<vector<int>> vis1(n,vector<int> (m,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis1[i][j] && grid1[i][j]==1){
                    dfs(i,j,grid1,vis1,delrow,delcol);
                }

                if(vis1[i][j]!=2 && grid2[i][j]==1){
                    int ans=1;
                    dfs2(i,j,grid2,vis1,delrow,delcol,ans);
                    if(ans){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};