class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int count=0;
        while(j<n){
            while(j<n && (nums[j]==nums[i])) j++;
            i++;
            if(j==n) return count+1;
            nums[i]=nums[j];
            count++;
        }
        return count;

    }
};