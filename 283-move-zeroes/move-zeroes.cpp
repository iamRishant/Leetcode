class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int right=0;
        int n=nums.size();
        while(left<n && nums[left]!=0) left++;
        if(left==n) return ;
        right=left+1;
        while(right<n){
            while(right<n && nums[right]==0) right++;
            if(right==n) break;
            swap(nums[left],nums[right]);
            left++;
        }
    }
};