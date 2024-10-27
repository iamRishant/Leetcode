class Solution {
public:
    bool check(int mid,int a,int b,int c,int n){
        long long sum=0;
        // finding lcm
        long long ab=(long long)(a*b)/__gcd(a,b);
        long long bc=(long long)(b/__gcd(b,c))*c;
        long long ac=(long long)(c*a)/__gcd(a,c);
        long long abc=(long long)(a*bc)/__gcd(a,(int)(bc));

         sum = (mid/a - mid/ab + mid/b - mid/bc + mid/c - mid/ac + mid/abc);
        // sum+=1;
        if(sum>=n) return true;
        
        return false;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int low=1;
        int high=2*1e9;

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,a,b,c,n)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};