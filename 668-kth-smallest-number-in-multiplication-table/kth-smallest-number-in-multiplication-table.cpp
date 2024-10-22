class Solution {
public:
    bool check(int mid,int k,int m,int n){
        int sum=0;
        for(int i=1;i<=m;i++){
            sum+=(min(mid/i,n));
            if(sum>=k) return true;
        }
        return false;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,k,m,n)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};