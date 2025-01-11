class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));

        for(auto it: queries){
            int r1=it[0];
            int c1=it[1];
            int r2=it[2];
            int c2=it[3];

            mat[r1][c1]+=1;
            if(c2+1<n) mat[r1][c2+1]-=1;
            if(r2+1<n) mat[r2+1][c1]-=1;
            if(r2+1< n && c2+1<n) mat[r2+1][c2+1]+=1;//do baar decrease ho gya so ek baar increase kr diya


        }

        // now just find prefix sum

        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                int up=0;
                int left=0;
                int diag=0;
                if(r-1>=0) up=mat[r-1][c];
                if(c-1>=0) left=mat[r][c-1];
                if(r-1>=0 && c-1>=0) diag=mat[r-1][c-1];

                mat[r][c]+=((up+left)-diag);
            }
        }

        return mat;
    }
};