class Solution {
public:
    int n,m;
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,set<pair<int,int>> &st,int delrow[],int delcol[]){
        st.insert({row,col});
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis,st,delrow,delcol);
            }
        }

    }
    void dfs2(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,set<pair<int,int>> &st,int delrow[],int delcol[],int &ans){
        // st.insert({row,col});
        auto it=st.find({row,col});
        if(it==st.end()){
            ans=0;

        }
        else {
            // cout<<"row "<<row<<" col "<<col<<endl;
            st.erase(it);
        }
        

        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs2(nrow,ncol,grid,vis,st,delrow,delcol,ans);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();

        vector<vector<int>> vis1(n,vector<int> (m,0));
        vector<vector<int>> vis2(n,vector<int> (m,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        set<pair<int,int>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis1[i][j] && grid1[i][j]==1){
                    dfs(i,j,grid1,vis1,st,delrow,delcol);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis2[i][j] && grid2[i][j]==1){
                    int ans=1;
                    dfs2(i,j,grid2,vis2,st,delrow,delcol,ans);
                    // cout<<"i "<<i<<" j "<<j<<endl;
                    if(ans){
                        // cout<<"row "<<i<<" col "<<j<<endl;

                        count++;
                    }
                }
            }
        }
        return count;
    }
};