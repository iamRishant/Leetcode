class Solution {
public:
    int solve(int curr,int n,vector<int> &dp){
        if(curr>n) return 0;

        if(curr==n) return 1;
        if(dp[curr]!=-1) return dp[curr];

        int one=solve(curr+1,n,dp);
        int two=solve(curr+2,n,dp);
        return dp[curr]=one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};