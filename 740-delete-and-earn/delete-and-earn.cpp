class Solution {
public:
    int solve(int index,vector<pair<int,int>> &pp,int n,vector<int> &dp){
        if(index>=n) return 0;
        int pick=0;
        int notPick=0;
        if(dp[index]!=-1) return dp[index];

        pick=pp[index].first*pp[index].second;
        if(index+1<n && pp[index+1].first-1!=pp[index].first) pick+=solve(index+1,pp,n,dp);
        else pick+=solve(index+2,pp,n,dp);
        notPick=solve(index+1,pp,n,dp);
        
        return dp[index]=max(pick,notPick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> pp;
        for(auto it: mp){
            pp.push_back({it.first,it.second});
        }
        sort(pp.begin(),pp.end());
        int sz=pp.size();
        vector<int> dp(sz+1,-1);
        return solve(0,pp,sz,dp);
    }
};