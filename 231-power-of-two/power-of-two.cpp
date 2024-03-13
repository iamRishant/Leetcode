class Solution {
public:
    bool isPowerOfTwo(int n) {
        // every number which is power of two have only one set bit 
        if(n<=0) return false;
        // n=abs(n);
        return !(n&(n-1));
    }
};