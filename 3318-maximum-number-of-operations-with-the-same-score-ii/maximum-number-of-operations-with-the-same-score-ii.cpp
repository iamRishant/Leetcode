class Solution {
public:
    int solve(int val,int start,int end,vector<int> &nums,vector<vector<int>> &dp){
        if(end<=start) return 0;
        
        if(dp[start][end]!=-1) return dp[start][end];
        
        int op1=0;
        int op2=0;
        int op3=0;
        if( nums[start]+nums[start+1]==val) op1=1+solve(val,start+2,end,nums,dp);
        if(nums[start]+nums[end]==val) op2=1+solve(val,start+1,end-1,nums,dp);
        if( nums[end]+nums[end-1]==val) op3=1+solve(val,start,end-2,nums,dp);
        
        return dp[start][end]= max(op1,max(op2,op3));
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int end=n-1;
        int start=0;
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // vector<vector<int>> dp2(n,vector<int> (n,-1));
        // vector<vector<int>> dp3(n,vector<int> (n,-1));

        int val1=nums[0]+nums[1];
        int val2=nums[0]+nums[end];
        int val3=nums[end]+nums[end-1];
        
        int ans1=1+solve(val1,2,end,nums,dp);
        int ans2=1+solve(val2,1,end-1,nums,dp);
        int ans3=1+solve(val3,0,end-2,nums,dp);
        
        return max(ans1,max(ans2,ans3));
        
    }
};