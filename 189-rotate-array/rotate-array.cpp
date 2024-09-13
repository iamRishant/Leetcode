class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // optimal

        int n=nums.size();
        k=k%n;
        int s1=0;
        int e1=n-k;
        int s2=n-k;
        int e2=n-1;
        reverse(nums.begin(),nums.begin()+e1);
        reverse(nums.begin()+s2,nums.end());
        reverse(nums.begin(),nums.end());

    }
};