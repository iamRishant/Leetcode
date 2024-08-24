class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
         multiset<int, greater<int> > s;
        int i=0;
        for(;i<k;i++){
            s.insert(nums[i]);
        }
        ans.push_back(*s.begin());
        for(;i<nums.size();i++){
            int prev=i-k;
            auto it=s.find(nums[prev]);
            s.erase(it);
            s.insert(nums[i]);
            ans.push_back(*s.begin());
        }
        return ans;
    }
};