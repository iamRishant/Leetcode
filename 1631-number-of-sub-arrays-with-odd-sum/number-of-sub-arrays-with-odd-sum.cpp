class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even=0;
        long long odd=0;
        int n=arr.size();
        long long sum=0;
        int  ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2!=0){
                ans=(ans%mod+1)%mod;
                ans=(ans%mod+even%mod)%mod;
                odd++;
            }
            else{
                ans=(ans%mod+odd%mod)%mod;
                even++;
            }
        }
        return ans%mod;
    }
};