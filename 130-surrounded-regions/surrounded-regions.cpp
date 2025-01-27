class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat){
        vis[row][col]=1;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,-1,0,1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<mat.size() && ncol<mat[0].size() && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        // traverse boundary and run a dfs on all the boundary O's

        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !vis[0][j]) dfs(0,j,vis,mat);
            if(mat[n-1][j]=='O' && !vis[n-1][j]) dfs(n-1,j,vis,mat);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]) dfs(i,0,vis,mat);
            if(mat[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,vis,mat);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j]) mat[i][j]='X';
            }
        }
        
    }
};