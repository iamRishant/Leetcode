class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        // first just check first and last element
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        // since we checked the first and last element then we reduced the search space
        int s=1;
        int e=n-2;
        while(e>=s){
            int mid=s+(e-s)/2;
            // now three 4 cases
            //1 mid is the peak
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            // so either on the decreasing side then peak on left
            else if(nums[mid]<nums[mid-1] ) e=mid-1;
            // either on the increasing side so peak on right
            else if(nums[mid]<nums[mid+1]) s=mid+1;
        }
        return -1;


    }
};