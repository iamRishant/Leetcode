class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long axb=0;
        for(int i=0;i<nums.size();i++){
            axb=axb^nums[i];
        }
        long long rightMostSet=(axb&axb-1) ^ axb;

        int bucket1=0;
        int bucket2=0;
        for(int i=0;i<nums.size();i++){
            if(rightMostSet & nums[i]){
                bucket1=bucket1^nums[i];
            }
            else bucket2=bucket2^nums[i];
        }

        return {bucket1,bucket2};
    }
};