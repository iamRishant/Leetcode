class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int second=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(first==nums.size()) return {-1,-1};
        if(nums.size()==0) return {-1,-1};
        if(nums[first]!=target) return {-1,-1};
        if(nums[first]==target && nums[second-1]==target) return {first,second-1};

        return {-1,-1};


    }
};