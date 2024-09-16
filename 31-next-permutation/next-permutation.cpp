class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // step 1 traverse from right find the index which smaller than its right
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1) reverse(nums.begin(),nums.end());
        else{
            // step 2 we need to find next greater element than idx so that we can swap it
            
            for(int i=nums.size()-1;i>idx;i--){
                if(nums[i]>nums[idx]){
                    swap(nums[idx],nums[i]);
                    // idx=i;
                    break;
                }
            }
            // after this we need to reverse the numbers after idx since they are increasing order and we need the smallest number after inx
            reverse(nums.begin()+idx+1,nums.end());

        }
    }
};