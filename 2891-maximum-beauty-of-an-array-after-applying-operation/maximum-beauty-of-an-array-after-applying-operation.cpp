class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
            // lien sweep method
            map<int,int> mp;
            int ans = 0;
            for(int i = 0;i<nums.size();i++){
                    mp[nums[i] - k] ++;
                    mp[nums[i] + k + 1] --;
                    
            }
            int count=0;
            // int ans=1;
            for(auto [a,b] : mp){
                    count+=b;
                    ans = max(ans,count);
            }
            return ans;
        
    }
};