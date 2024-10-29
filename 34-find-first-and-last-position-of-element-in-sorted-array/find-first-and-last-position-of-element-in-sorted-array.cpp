class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int occ=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(occ==-1 || occ==nums.size() || nums[occ]!=target) return {-1,-1};
        int left=occ;
        int right=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        return {left,right};
    }
};