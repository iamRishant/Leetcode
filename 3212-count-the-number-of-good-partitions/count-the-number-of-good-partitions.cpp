class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int res=1;
        int n=nums.size();

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int i=0;
        int j=mp[nums[i]];

        long long mod=1e9+7;

        while(i<n){
            if(i>j){
                res=(long long)res *2;
                res=res%mod;
                j=mp[nums[i]];
            }
            j=max(j,mp[nums[i]]);
            i++;
        }

        res=res%mod;
        return res;
    }
};