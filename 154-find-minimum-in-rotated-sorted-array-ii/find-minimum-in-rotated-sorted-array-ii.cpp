class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=nums[0];
        if(n==1) return ans;

        while(e>=s){
            int mid=s+(e-s)/2;
            ans=min(ans,nums[mid]);
            // left sorted then we will move to right side 
            if(nums[mid]==nums[s] && nums[s]==nums[e] ) {s++;e--;}
            else if(nums[mid]>=nums[s]){
                if(s<=e)
                ans=min(ans,nums[s]);
                s=mid+1;
            }
            else if(nums[mid]<=nums[e]) e=e-1;
        }
        return ans;
    }
};