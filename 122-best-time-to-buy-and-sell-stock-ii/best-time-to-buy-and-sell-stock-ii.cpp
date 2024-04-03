class Solution {
public:
    int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp){
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if(buy){
            // bought or not bought
            profit=max(-prices[index]+solve(index+1,0,prices,dp),0+solve(index+1,1,prices,dp));
        }
        else{
            // sold or not not sold
            profit=max(prices[index]+solve(index+1,1,prices,dp),0+solve(index+1,0,prices,dp));
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        // return solve(0,1,prices,dp);   
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,0));
        
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;

                if(buy){
            // bought or not bought
                    profit=max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
                }
                else{
                    // sold or not not sold
                    profit=max(prices[index]+dp[index+1][1],0+dp[index+1][0]);
                }

                dp[index][buy]=profit;
                
            }
        }
        return dp[0][1];

    }
};