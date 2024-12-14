class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        int n=nums.size();
        vector<long long> preFix(n+1,0);
        for(int i=0;i<n;i++) preFix[i+1]=preFix[i]+nums[i];

        vector<long long> mini(k,LLONG_MAX);

        for(int i=0;i<=n;i++){
            int rem=i%k;

            if(i>=k){
                ans=max(ans,preFix[i]-mini[rem]);
            }
            mini[rem]=min(mini[rem],preFix[i]);
        }
        return ans==-1e18?-1:ans;
    }
};