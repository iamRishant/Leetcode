class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            // first check which side is sorted
            if(nums[mid]==target) return mid;
            else if(nums[low]<=nums[mid]){
                // it means left side is sorted
                if(target<nums[mid] && target>=nums[low]) high=mid-1;
                else low=mid+1;
            }
            else if(nums[high]>=nums[mid]){
                // it means right side is sorted
                if(target > nums[mid] && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
        
    }
};