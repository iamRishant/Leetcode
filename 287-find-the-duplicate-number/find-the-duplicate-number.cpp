class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // tortoise and hare method
        int slow=nums[0];
        int fast=nums[0];
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(fast==slow){
                slow=nums[0];
                while(fast!=slow){
                    slow=nums[slow];
                    fast=nums[fast];

                }
                return fast;
            }
        }
        return 0;
    }
};