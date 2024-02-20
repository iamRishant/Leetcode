class Solution {
public:
    int solve(int start,int end,vector<int> &nums,int target){
        if(end<start) return -1;
        
        int mid=(start+end)/2;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) return solve(mid+1,end,nums,target);
        else return solve(start,mid-1,nums,target);
    }
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        return solve(start,end,nums,target);
    }
};