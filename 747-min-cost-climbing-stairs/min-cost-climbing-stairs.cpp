class Solution {
public:
    int solve(int curr,vector<int> &cost,vector<int> &dp){
        if(curr>=cost.size()) return 0;

        if(dp[curr]!=-1) return dp[curr];

        int j1=cost[curr]+solve(curr+1,cost,dp);
        int j2=cost[curr]+solve(curr+2,cost,dp);

        return dp[curr]= min(j1,j2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp1(cost.size()+1,-1);
        vector<int> dp2(cost.size()+1,-1);
        return min(solve(0,cost,dp1),solve(1,cost,dp2));
    }
};