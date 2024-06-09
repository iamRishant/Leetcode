class Solution {
public:
    int solve(int index,vector<int> &nums,int k,int n,int prev_val_ind,vector<vector<vector<int>>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][k][prev_val_ind+1]!=-1) return dp[index][k][prev_val_ind+1];

        
        int pick=0;
        if( prev_val_ind==-1 || nums[prev_val_ind]==nums[index]){
            pick=1+solve(index+1,nums,k,n,index,dp);
        }
        else if((k>0 && nums[prev_val_ind]!=nums[index])){
            pick=1+solve(index+1,nums,k-1,n,index,dp);
        }
         
        int notPick=0+solve(index+1,nums,k,n,prev_val_ind,dp);

        return dp[index][k][prev_val_ind+1]= max(pick,notPick);
    }
    int maximumLength(vector<int>& nums, int k) {

        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (26,vector<int>(n+5,-1)));
        int prev_val_ind=-1;
        return solve(0,nums,k,n,prev_val_ind,dp);
    }
};