class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[entrance[0]][entrance[1]]=1;
        queue<pair<pair<int,int>,int>> q;//i,j,dis;
        q.push({{entrance[0],entrance[1]},0});

        int delrow[]={0,1,0,-1};
        int delcol[]={-1,0,1,0};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            // vis[row][col]=1;
            int dis=it.second;
            

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && maze[nrow][ncol]=='.'){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol]=1;
                }
                else if((nrow<0 || ncol<0 || nrow>=n || ncol>=m) && dis!=0 ) return dis;
            }
            
        }
        return -1;
    }
};