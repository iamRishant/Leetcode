class Solution {
public:
    int findMin(vector<int>& nums) {
        //there can be 4 case >> << <> ><
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return min(nums[0],nums[1]);

        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            // case 1 >>
            if(nums[low]>nums[mid] && nums[mid]>nums[high]){
                low=mid+1;
            }
            // case 2 <<
            else if(nums[low]<nums[mid] && nums[mid]<nums[high]){
                high=mid-1;
            }
            //case 3 <>
            else if(nums[mid]>nums[high] && nums[mid]>nums[low]){
                if(nums[high]>nums[low]){
                    high=mid-1;
                }
                else low=mid+1;
            }
            // case 4 >< since sorted hai to ise chota wala ye to yhi hoga yaleft me hoga
            else if(nums[high]>nums[mid] && nums[low]>nums[mid]) high=mid;
            else return min(nums[low],nums[high]);

        }

        return nums[low];
    }
};