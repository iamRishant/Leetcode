class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // brute by sorting
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i) return i;
            else i++;
        }
        return i;
    }
};