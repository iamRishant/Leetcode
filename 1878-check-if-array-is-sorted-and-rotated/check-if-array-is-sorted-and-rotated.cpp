class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            int ind=i%n;

            if(nums[ind]<nums[i-1]) count++;
        }
        return count<=1;
    }
};