class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cntz=0;
        int left=0;
        int maxi=0;
        int n=nums.size();
        // int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cntz++;
            while(cntz>k){
                if(nums[left]==0) cntz--;
                left++;
            }
            maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};