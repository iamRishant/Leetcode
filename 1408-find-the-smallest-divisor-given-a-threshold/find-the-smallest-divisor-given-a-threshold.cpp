class Solution {
public:
    bool check(int mid,vector<int> &nums,int t){
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=(nums[i]+mid-1)/mid;
            if(curr>t) return false;
        }
        if(curr<=t) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=1e6;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(mid,nums,threshold)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};