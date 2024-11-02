class Solution {
public:
    bool check(int mid,vector<int> & arr, int k){
        int numBehind=upper_bound(arr.begin(),arr.end(),mid)-arr.begin();
        int total=mid-1;
        int value=total-numBehind+1;//it means this number mid is the valueth position
        if(value<k) return false;
        return true;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=1;
        int high=arr[n-1]+k;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,arr,k)){
                // ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};