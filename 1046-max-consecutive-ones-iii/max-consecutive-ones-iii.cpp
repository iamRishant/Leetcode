class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int ans=0;
        while(right<nums.size()){
            if(nums[right]==1 || (nums[right]==0 && k>0)){
                ans=max(ans,right-left+1);
                if(nums[right]==0) k--;
                right++;
            } 
            else if(nums[right]==0 && k==0){
                while(nums[left]!=0){
                    left++;
                }
                left++;
                k++;
            }      
        }
        return ans;
    }
};