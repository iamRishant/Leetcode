class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0){
                winner=nums[i];
                count=1;
                continue;
            }
            if(nums[i]==winner) count++;
            else {
                count--;
            }

        }
        return winner;
        
    }
};