class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int count=0;
        int right=0;
        int left=0;
        int n=nums.size();
        int countOfZero=0;
        while(right<n){
            if(nums[right]==0) countOfZero++;
            while(countOfZero>k){
                if(nums[left]==0) countOfZero--;
                left++;
            }
            ans=max(right-left+1,ans);
            right++;
                
            }
            return ans;
        
    }
};