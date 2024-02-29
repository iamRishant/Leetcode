class Solution {
public:
    int check(int mid,vector<int> nums,int threshold){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(ceil(nums[i]/(mid*1.0)));
            if(ans>threshold) return 0;
        }
        return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=-1;

        for(int i=0;i<nums.size();i++){
            // l=min(l,nums[i]);
            h=max(h,nums[i]);
        }
        int ans=h;
        while(h>=l){
            int mid=l+(h-l)/2;
            int val=check(mid,nums,threshold);
            if(val){
                ans=min(ans,mid);
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};