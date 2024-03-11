class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> mat2(mat.size(),vector<int>(mat[0].size(),0));
        queue <pair<pair<int,int>,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0) q.push({{i,j},0});
            }
        }
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            int f=q.front().first.first;
            int s=q.front().first.second;
            int d=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int r=row[i]+f;
                int c=col[i]+s;
                if(r>=0&&r<mat.size()&&c>=0&&c<mat[r].size()&&mat[r][c]==1&&mat2[r][c]==0){
                    mat2[r][c]=d+1;
                    q.push({{r,c},d+1});
                }
            }
        }
        return mat2;
    }
};