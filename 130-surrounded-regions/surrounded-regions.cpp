class Solution {
public:
    void solve(int row,int col,vector<vector<int>> &vis){
        vis[row][col]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<vis.size() && ncol>=0 && ncol<vis[0].size() && !vis[nrow][ncol]){
                solve(nrow,ncol,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X') vis[i][j]=1;
            }
        }
        
        // visiting first and last row

        for(int col=0;col<m;col++){
            if(!vis[0][col]) solve(0,col,vis);
            if(!vis[n-1][col]) solve(n-1,col,vis);
        }

        for(int row=0;row<n;row++){
            if(!vis[row][0]) solve(row,0,vis);
            if(!vis[row][m-1]) solve(row,m-1,vis);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};