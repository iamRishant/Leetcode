class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int start=0;
        int end=0;
        int prod=1;
        int ans=0;
        for(;end<nums.size();end++){
            prod=prod*nums[end];
            while(prod>=k){
                prod=prod/nums[start++];
            }
            if(prod<k){
                ans+=(end-start)+1;
            }
        }
        return ans;
        
    }
};