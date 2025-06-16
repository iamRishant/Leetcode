class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minTillNow=nums[0];
        int ans=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>minTillNow){
                ans=max(ans,nums[i]-minTillNow);
            }
            minTillNow=min(minTillNow,nums[i]);
        }
        return ans;
    }
};