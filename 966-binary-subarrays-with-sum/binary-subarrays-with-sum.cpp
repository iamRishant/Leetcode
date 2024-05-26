class Solution {
public:
    int solve(vector<int> nums,int goal){
        if(goal<0) return 0;
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;
        while(r<nums.size()){
            sum+=nums[r];

            // if sum is grater than goal then reduce it
            while(sum>goal){
                sum-=nums[l];
                l++;
            }

            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // hasing will be better solution but not optimal and making alll substring will be brute 
        // so we will be using sliding windown and 2 pointer 
        // ans will be find all substring sum <=k - all substring sum<=k-1

        return solve(nums,goal)-solve(nums,goal-1);
    }
};