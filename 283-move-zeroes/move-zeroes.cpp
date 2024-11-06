class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int start=0;

        while(curr<n){
            if(nums[curr]!=0){
                swap(nums[curr],nums[start]);
                start++;
            }
            curr++;
        }
    }
};