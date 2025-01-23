class Solution {
public:
    long long solve(int index,vector<vector<int>> &cost,int left,int right,vector<vector<vector<long long>>> &dp,int n){
        if(index==(n/2)){
            return 0;
        }

        if(dp[index][left+1][right+1]!=-1) return dp[index][left+1][right+1];

        long long ans=1e18;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k || j==left || k==right) continue;

                long long temp=cost[index][j]+cost[n-index-1][k]+solve(index+1,cost,j,k,dp,n);
                ans=min(temp,ans);
            }
        }
        return dp[index][left+1][right+1] = ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        // int n=cost.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (5,vector<long long> (5,-1)));//i,j,k
        return solve(0,cost,-1,-1,dp,n);
    }
};