class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long sum=0;
        long long  i=0;
        long long j=1;
        long long n=nums.size();
        while(j<n){
            while(j<n && nums[i]>=nums[j]) j++;
            if(j==n) j--;
            sum+=(long long)(nums[i]*(j-i));
            i=j;
            j=j+1;
        }
        return sum;
    }
};