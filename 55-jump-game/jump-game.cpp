class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxi=0;
        int currEnd=nums[0];
        int curr=0;
        int n=nums.size();
        while(curr<n){
            maxi=max(maxi,curr+nums[curr]);

            if(maxi>=n-1) return true;
            if(curr==maxi) return false;
            if(curr==currEnd){
                currEnd=maxi;
            }
            curr++;
        }
        return true;
    }
};