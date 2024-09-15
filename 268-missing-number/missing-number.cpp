class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        long long toSum=n*(n+1)/2;
        return toSum-sum;
    }
};