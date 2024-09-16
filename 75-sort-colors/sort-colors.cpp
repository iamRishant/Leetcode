class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;//for 0
        int j=0;//for 1
        int k=n-1;//for 2

        while(k>=j){
            if(nums[j]==2){
                swap(nums[j],nums[k--]);// j has 2 it will swap with k
            }
            else if(nums[j]==1) j++;// j has 1 
            else swap(nums[j++],nums[i++]);// it means j has 0 he dont wants it so he will swap it with i
        }
    }
};