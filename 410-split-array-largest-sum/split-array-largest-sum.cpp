class Solution {
public:
    bool check(int mid,vector<int> &nums,int k){
        int curr=0;
        int seg=1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr>mid){
                seg++;
                curr=nums[i];
            }
            if(seg>k) return false;
        }
        if(seg<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        
        int ans=low;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};