class Solution {
public:
    int solve(int index,vector<int> &nums,int n,vector<int> &dp){
        if(index>=n) return 0;

        if(dp[index]!=-1) return dp[index];

        int one=nums[index]+solve(index+2,nums,n,dp);
        int two=0+solve(index+1,nums,n,dp);

        return dp[index]= max(one,two);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};