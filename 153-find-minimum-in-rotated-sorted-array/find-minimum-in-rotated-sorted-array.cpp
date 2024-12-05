class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=nums[0];//if left sorted
        while(low<=high){
            int mid=(low+high)/2;
            // if left sorted
            if(nums[mid]>=nums[low]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
            // if it is right sorted then mid can be possible answer
                ans=min(ans,nums[mid]);
                high=mid-1;

            }
        }
        return ans;
    }
};