class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // properties of bitwise operator
        // A^A=0
        // A^B^A=B
        // (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
        // Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
        // also 0^A=A
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
        // now i know how it works
    }
};