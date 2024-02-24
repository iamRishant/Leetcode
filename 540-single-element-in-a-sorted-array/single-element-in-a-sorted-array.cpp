class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        if(nums.size()==1) return nums[0];
        while(e>=s){
            int mid=s+(e-s)/2;
            if(s==e) return nums[s];
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            else if(nums[mid]==nums[mid+1]){
                if((e-mid+1)%2==0) e=mid-1;
                else s=mid+2; 
            }
            else if(nums[mid]==nums[mid-1]){
                if((mid-s+1)%2==0) s=mid+1;
                else e=mid-2;
            }
        }
        return 0;
    }
};