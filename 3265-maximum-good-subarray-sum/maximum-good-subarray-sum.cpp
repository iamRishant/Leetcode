class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<long long,long long> mp;
        long long currSum=0;
        long long ans=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            long long rem1=nums[i]-k;
            long long rem2=nums[i]+k;
            if(mp.find(rem1)!=mp.end()){
                long long val=currSum+nums[i]-mp[rem1];
                ans=max(ans,val);
            }
            if(mp.find(rem2)!=mp.end()){
                long long val=currSum+nums[i]-mp[rem2];
                ans=max(ans,val);
            }

            if(mp.find(nums[i])==mp.end()) mp[nums[i]]=currSum;
            else{
                mp[nums[i]]=min(mp[nums[i]],currSum);
            }

            currSum+=nums[i];
        }
        return ans==LLONG_MIN ? 0:ans;
    }
};
// https://www.youtube.com/watch?v=e3w9YX32X38