class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;

        while(high>=low){
            int mid=low+(high-low)/2;
            int rem=arr[mid]-(mid+1);
            if(rem>=k) high=mid-1;
            else low=mid+1;
        }
        return k+high+1;
    }
};