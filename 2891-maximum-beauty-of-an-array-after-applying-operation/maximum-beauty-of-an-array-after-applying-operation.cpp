class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=1;
        for(int i=0;i<nums.size();i++){
            int idx=upper_bound(nums.begin(),nums.end(),nums[i]+(2*k))-nums.begin();
            maxi=max(maxi,idx-i);
        }
        return maxi;

    }
};