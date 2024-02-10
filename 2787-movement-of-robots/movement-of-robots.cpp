class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        // vector<int> Final;
        int mod=1e9+7;
        int n=nums.size();
        for(long long i=0;i<nums.size();i++){
            if(s[i]=='L') nums[i]=nums[i]%mod-d;
            else nums[i]=nums[i]%mod+d;
        }

        vector<long long > preFix(n,0);
        preFix[0]=0;
        preFix[0]=nums[0];
        sort(nums.begin(),nums.end());
        
        long long ans=0,sum=0;
        for(long long i=0;i<n;i++){
            ans=(ans+(nums[i]*i-sum)%mod)%mod;
            sum=(sum%mod+nums[i]%mod)%mod;
        }

        return ans%mod;
    }
};
// https://www.youtube.com/watch?v=2MVtL9g_GEA