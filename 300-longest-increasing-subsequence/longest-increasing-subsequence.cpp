class Solution {
public:
    int solve(int index,int prev_index,vector<int> &nums,vector<vector<int>> &dp){
        if(index==nums.size()) return 0;

        if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
        // not pick
        int len=0+solve(index+1,prev_index,nums,dp); 
        // pick
        if(prev_index==-1 || nums[index]>nums[prev_index]){
            len=max(len,1+solve(index+1,index,nums,dp));
        }

        return dp[index][prev_index+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(0,-1,nums,dp);

        // binary search
        // vector<int> ans;
        // ans.push_back(nums[0]);

        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]>ans.back()){
        //         ans.push_back(nums[i]);
        //     }
        //     else{
        //         int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
        //         ans[index]=nums[i];
        //     }
        // }
        // return ans.size();

    }
};