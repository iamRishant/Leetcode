class Solution {
public:
    int mod=1e9+7;
    long long power(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        long long prod1=power(5,n/2)%mod;
        long long prod2=power(4,n/2)%mod;
        long long ans=1LL * prod1 * prod2;
        if(n%2){
            ans=ans*5;
        }
        ans=ans%mod;
        return ans;
    }
};