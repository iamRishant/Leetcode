class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
            // check if left half is sorted
            else if(nums[s]<=nums[mid]){
                // if target exist in left half
                if(target>=nums[s] && nums[mid]>=target){
                    e=mid-1;
                }
                else s=mid+1;
            }
            // else it is right sorted
            else if(nums[mid]<=nums[e]){
                if(target>=nums[mid] && target<=nums[e]){
                    s=mid+1;
                }
                else e=mid-1;
            }
        }
        return -1;
    }
};