class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>=nums.size()-1) return 1;
        int jump=0;
        int index=0;
        int currRange=nums[0];
        int maxRange=nums[0];
        int n=nums.size();
        while(index<nums.size()){
            maxRange=max(maxRange,index+nums[index]);

            if(index==currRange){
                currRange=maxRange;
                jump++;
                if(maxRange>=n-1) return jump+1;
                
            }
            index++;
        }
        return jump;
    }
};