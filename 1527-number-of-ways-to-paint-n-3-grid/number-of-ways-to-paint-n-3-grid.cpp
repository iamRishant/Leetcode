class Solution {
public:
    int mod=1e9+7;
    // possible movies for first row 
    string moves[12]={
        "123",
        "132",
        "121",
        "131",
        "213",
        "231",
        "232",
        "212",
        "312",
        "321",
        "313",
        "323",
    };
    int solve(int n,int idx,vector<vector<int>> &dp){
        if(n==0) return 1;// we got one possible solution

        if(dp[n][idx]!=-1) return dp[n][idx];
        string prevMove=moves[idx];
        int ans=0;
        for(int i=0;i<12;i++){
            string curr=moves[i];
            // now we will match all the moves again and jo condition match krega usko aage 
            // recursion ke liye bhejenge
            bool same=false;
            for(int j=0;j<3;j++) if(prevMove[j]==curr[j]) same=true;
            if(!same) ans=(ans+solve(n-1,i,dp)%mod)%mod;
        }
        return dp[n][idx]=ans;
    }
    int numOfWays(int n) {
        vector<vector<int>> dp(n+1,vector<int> (12,-1));
        int ans=0;
        for(int i=0;i<12;i++){
            ans=(ans+solve(n-1,i,dp)%mod)%mod;

        }

        return ans;
    }
};