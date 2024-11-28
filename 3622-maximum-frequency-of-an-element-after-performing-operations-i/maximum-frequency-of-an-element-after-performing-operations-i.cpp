class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> range;
        unordered_map<int,int> freq;
        int minRange=1e9;
        int maxRange=-1e9;

        int n=nums.size();
        for(int i=0;i<n;i++){
            minRange=min(minRange,nums[i]-k);
            maxRange=max(maxRange,nums[i]+k+1);

            freq[nums[i]]++;
            range[nums[i]-k]++;
            range[nums[i]+k+1]--;
        }

        int ans=1;
        // now using line sweeep on range
        for(int i=minRange;i<=maxRange;i++){
            range[i]+=range[i-1];
            int actualPower=range[i]-freq[i];

            int tempAns=freq[i]+min(numOperations,actualPower);

            ans=max(ans,tempAns);
        }
        return ans;
    }
};