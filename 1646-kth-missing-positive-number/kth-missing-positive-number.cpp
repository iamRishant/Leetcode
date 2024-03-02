class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int range=arr[n-1]+k;
        // cout<<range<<" ";
        for(int i=1;i<=range;i++){
            int index=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
            if((index>=n || index<0) || arr[index]!=i) k--;
            if(k==0) return i;
        }
        return -1;
    }
};