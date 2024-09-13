class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        while(left<n){
            while(left<n && nums[left]!=0) left++;
            // now here left is pointing to 0
            int right=left+1;
            while(right<n &&nums[right]==0) right++;
            // now here right is just pointing a non zero number 
            
            if(left>=n || right>=n) break;
            swap(nums[left],nums[right]);
            left++;
        }
    }
};