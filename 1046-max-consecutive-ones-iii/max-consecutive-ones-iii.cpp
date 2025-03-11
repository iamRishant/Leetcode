class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        int count0=0;
        int ans=0;
        while(right<n){
            if(nums[right]==0) count0++;
            while(count0>k){
                if(nums[left]==0) count0--;
                left++;   
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};