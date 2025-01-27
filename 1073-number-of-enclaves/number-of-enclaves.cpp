class Solution {
public:
void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &mat){
        vis[row][col]=1;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<mat.size() && ncol<mat[0].size() && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                dfs(nrow,ncol,vis,mat);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        // traverse boundary and run a dfs on all the boundary O's

        for(int j=0;j<m;j++){
            if(mat[0][j]==1 && !vis[0][j]) dfs(0,j,vis,mat);
            if(mat[n-1][j]==1 && !vis[n-1][j]) dfs(n-1,j,vis,mat);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1 && !vis[i][0]) dfs(i,0,vis,mat);
            if(mat[i][m-1]==1 && !vis[i][m-1]) dfs(i,m-1,vis,mat);
        }

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
};