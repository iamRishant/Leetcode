class Solution {
public:

void dfs(int row,int col,int &sum,vector<vector<int>> &vis,vector<vector<int>> &grid ){



    sum+=grid[row][col];
    vis[row][col]=1;
    int delrow[]={0,1,0,-1};
    int delcol[]={-1,0,1,0};
    for(int i=0;i<4;i++){

        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]>0){

            dfs(nrow,ncol,sum,vis,grid);
        }
    }



}
    int findMaxFish(vector<vector<int>>& grid) {
     int maxi=0;
     int n=grid.size();
     int m=grid[0].size();

     vector<vector<int>>  vis(n,vector<int> (m,0));

     for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            if(grid[i][j]==0) vis[i][j]=1;
        }
     }


     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                int sum=0;
                dfs(i,j,sum,vis,grid);
                // cout<<sum<<endl;
                maxi=max(maxi,sum);
            }
        }
     }   
     return maxi;
    }
};