class Solution {
public:
    int solve(vector<int> nums,int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        int ans=0;
        int count=0;

        while(r<nums.size()){
            if(nums[r]%2!=0) count++;
            while(count>k){
                if(nums[l]%2!=0) count--;
                l++;
            }
            if(count<=k) ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // i think we have to use <=k and <=k-1 method to solve this
        return solve(nums,k)-solve(nums,k-1); 
    }
};