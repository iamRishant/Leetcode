class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[low]){
                //it means left sorted
                if(target>=nums[low] && target<nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(target<=nums[high] && nums[mid]<target) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};