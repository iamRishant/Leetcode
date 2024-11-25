class Solution {
public:
    int solve(int index,vector<int> &nums,int op1,int op2,int k,vector<vector<vector<int>>> &dp){
        if(index==nums.size()) return 0;
        if(dp[index][op1][op2]!=-1) return dp[index][op1][op2];
        int pick=0;
        int notPick=1e9;
        notPick=nums[index]+solve(index+1,nums,op1,op2,k,dp);
        // for pick i think i have 6 option either -3 or /2 or both or /2 or -3 or both
        int opt1=1e9;
        int opt2=1e9;
        int opt3=1e9;
        int opt4=1e9;

        if(op1>0) opt1=((nums[index]+1)/2)+solve(index+1,nums,op1-1,op2,k,dp);
        if(op2>0 && nums[index]>=k) opt2=(nums[index]-k)+solve(index+1,nums,op1,op2-1,k,dp);
        if(op1>0 && op2>0 && nums[index]>=k){
                opt3=((nums[index]-k+1)/2)+solve(index+1,nums,op1-1,op2-1,k,dp);
                if(((nums[index]+1)/2)>=k) opt4=(((nums[index]+1)/2)-k)+solve(index+1,nums,op1-1,op2-1,k,dp);
        }

        return dp[index][op1][op2] =min(notPick,min(opt1,min(opt2,min(opt3,opt4))));
        

    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (op1+1,vector<int> (op2+1,-1)));
        return solve(0,nums,op1,op2,k,dp);
    }
};