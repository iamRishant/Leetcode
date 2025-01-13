class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;

        int left=0;
        int right=0;
        int n=nums.size();

        long long sum=0;
        while(right<n){
            sum+=nums[right];
            while(left<=right && (right-left+1)*sum>=k){
                sum-=nums[left];
                left++;
            }
            ans+=(right-left+1);

            right++;
        }
        return ans;
    }
};