class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int ,int> range;
        map<int ,int > freq;
        int minRange=2e9;
        int maxRange=-2e9;
        //this time rather than traversing form minrange to maxrange which is not possible 
        // we will only iterate on critical points coz major changes wohi hue honge

        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            range[nums[i]-k]++;
            range[nums[i]+k+1]--;
            range[nums[i]]+=0;//jusst adding for the sake that it is present in it this will be critical points
            minRange=min(minRange,nums[i]-k);
            maxRange=max(maxRange,nums[i]+k+1);
        }

        int prev=0;
        int ans=1;
        for(auto it=range.begin();it!=range.end();it++){
            it->second+=prev;
            prev=it->second;
            // upar jo kiye wo sweep line hi hai
            // now we got the range
            int actualPower=it->second-freq[it->first];
            int tempAns=freq[it->first]+min(numOperations,actualPower);

            ans=max(ans,tempAns);
        }
        return ans;
    }
};