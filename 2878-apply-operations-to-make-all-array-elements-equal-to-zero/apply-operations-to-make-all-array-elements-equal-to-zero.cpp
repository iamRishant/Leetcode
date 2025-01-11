class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> diffArr(n+1,0);

        int currSum=0;
        for(int i=0;i<=n-k;i++){
            if(i>0) diffArr[i]+=diffArr[i-1];
            currSum=diffArr[i];

            if(currSum>nums[i]) return false;
            diffArr[i]+=(nums[i]-currSum);
            diffArr[i+k]-=(nums[i]-currSum);
            // currSum+=diffArr[i];
        }
        for(int i=n-k+1;i<=n;i++){
            diffArr[i]+=diffArr[i-1];

        }
        for(int i=0;i<n;i++) if(nums[i]!=diffArr[i]) return false;
        return true;
    }
};