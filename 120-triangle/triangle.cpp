class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==n-1) return triangle[i][j];
        if(i>=n) return 0;

        // int left=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=0;
        int right=0;

        // if(j-1>=0) left=triangle[i][j]+solve(i+1,j-1,n,triangle);
        down=triangle[i][j]+solve(i+1,j,n,triangle,dp);
        right=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);

        return dp[i][j]=min(right,down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(0,0,n,triangle,dp);
    }
};