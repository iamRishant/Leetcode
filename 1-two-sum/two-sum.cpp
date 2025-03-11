class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int s=target-nums[i];
            if(mp.find(s)!=mp.end()) return {mp[s],i};

            mp[nums[i]]=i;
        }
        return {};
    }
};