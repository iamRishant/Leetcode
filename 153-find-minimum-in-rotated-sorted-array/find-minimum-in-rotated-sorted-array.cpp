class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=nums[0];

        while(e>=s){
            int mid=s+(e-s)/2;
            ans=min(ans,nums[mid]);
            // left sorted then we will move to right side 
            if(nums[mid]>=nums[s]){
                s=mid+1;
                if(s<=e)
                ans=min(ans,nums[s]);
            }
            else if(nums[mid]<=nums[e]) e=e-1;
        }
        return ans;
        
    }
};