class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int left=0;
            int right=0;
            if(mid==0) left=INT_MIN;
            else left=nums[mid-1];
            if(mid==n-1) right=INT_MIN;
            else right=nums[mid+1];

            if(nums[mid]>left && nums[mid]>right) return mid;
            else if(nums[mid]>left && nums[mid]<right) low=mid+1;
            else if(nums[mid]>right && nums[mid]<left) high=mid-1;
            else low=mid+1;//mtlb lowest point par hai kahi jao left right peak mil hi jaega
        }
        return 0;
    }
};