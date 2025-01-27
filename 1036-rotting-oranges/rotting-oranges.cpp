class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));

        int fresh=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1) fresh++;
                else vis[i][j]=1;
            }
        }

        int countRotten=0;
        int maxTime=0;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int time=it.second;
            maxTime=max(time,maxTime);
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size()  && !vis[nrow][ncol] ){
                    vis[nrow][ncol]=1;
                    countRotten++;
                    q.push({{nrow,ncol},time+1});
                }
            }

        } 
        if(fresh!=countRotten) return -1;
        return maxTime;
    }
};