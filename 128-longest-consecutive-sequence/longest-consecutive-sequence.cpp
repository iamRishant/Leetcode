class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        int ans=0;
        for(auto &num: nums){
            if(s.find(num-1)==s.end()){
                //this means this is start of seq
                int count=1;
                int curr=num+1;
                while(s.find(curr)!=s.end()){
                    count++;
                    curr=curr+1;
                }
                ans=max(ans,count);
            }
        }
        return ans;

    }
};