class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // lets treat 0 as -1 then question will break down to finding largert sb arraywith sum 0
        map<int,int> mp;
        int sum=0;
        int maxLen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum--;
            else sum++;
            if(sum==0){
                maxLen=i+1;
            }

            int rem=sum;
            if(mp.find(rem)!=mp.end()){
                int len=mp[rem];
                maxLen=max(i-len,maxLen);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return maxLen;
    }
};