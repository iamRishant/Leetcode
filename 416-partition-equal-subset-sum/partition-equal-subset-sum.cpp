class Solution {
public:
    int n;
    bool solve(int idx,int currSum,vector<int> &arr,vector<vector<int>> &dp,int target){
        if(currSum==target) return true;
        if(currSum>target) return false;
        if(idx==n) return false;

        if(dp[idx][currSum]!=-1) return dp[idx][currSum];

        bool pick=solve(idx+1,currSum+arr[idx],arr,dp,target);
        bool notPick=solve(idx+1,currSum,arr,dp,target);

        return dp[idx][currSum]=pick||notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;

        int target=(sum/2);

        n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return solve(0,0,nums,dp,target);
    }
};