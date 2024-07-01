class Solution {
public:
    int solve(int index,vector<int> &nums,int n,vector<int> &dp){
        if(index+nums[index]>=n-1) return 1;
        if(nums[index]==0) return 1e9;

        if(dp[index]!=-1) return dp[index];

        int ans=INT_MAX;
        for(int i=index+1;i<=min(index + nums[index], n - 1);i++){
            int temp=1+solve(i,nums,n,dp);
            ans=min(ans,temp);
        }
        return dp[index]= ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]==0 || n==1) return 0;
        // if(n==1) return 1;
        vector<int> dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};