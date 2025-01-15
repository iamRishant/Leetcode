class Solution {
public:
    bool check(long long mid,vector<int> arr,int r,int k){
        long long sum=0;
        for(int i=0;i<r;i++) sum+=arr[i];
        int n=arr.size();
        for(int i=0;i<n;i++){
            // adjusting window
            if(i+r<n){
                sum+=arr[i+r];
            }
            if(i-r-1>=0) sum-=arr[i-r-1];

            if(sum<mid){
                //jitna req hai usse kam hai power
                long long req=mid-sum;
                if(req>k) return false;
                arr[min(i+r,n-1)]+=req;
                k-=req;
                sum=mid;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long low=0;
        long long high=k;
        int n=stations.size();
        for(int i=0;i<n;i++) high+=stations[i];

        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid,stations,r,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }
};