class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int n=nums.size();
        int curr=0;
        int currEnd=nums[0];
        int maxEnd=0;
        if(n==1) return 0;

        while(curr<n){
            maxEnd=max(maxEnd,curr+nums[curr]);

            // if(curr==maxEnd) return -1;
            if(curr==currEnd){
                currEnd=maxEnd;
                jump++;
            }
            if(currEnd>=n-1) return jump+1;
            curr++;
        }
        return jump;
    }
};