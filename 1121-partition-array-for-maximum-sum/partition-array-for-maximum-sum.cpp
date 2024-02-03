class Solution {
public:
    int solve(int index,vector<int> &arr,int k,vector<int> &dp){
        if(index==arr.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        int len=0;
        int maxSum=0;//stores the answer
        int currMax=0;//jo current window hoga uska max store krega
        for(int j=index;j < index+k && j < arr.size();j++){
            len++;
            currMax=max(currMax,arr[j]);
            int sum=len*currMax+ solve(j+1,arr,k,dp);
            maxSum=max(sum,maxSum);
        }
        return dp[index]= maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return solve(0,arr,k,dp);
    }
};