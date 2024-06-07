class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        set<int> s;

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            s.insert(nums[i]);
        }

        int l=0;
        while(l+k<=nums.size()){
            ans.push_back(*s.rbegin());
            if(l+k<nums.size()){
                int outgoing=nums[l];
                mp[outgoing]--;
                if(mp[outgoing]==0) {
                    mp.erase(outgoing);
                    s.erase(outgoing);
                }
                
                int incoming=nums[l+k];
                s.insert(incoming);
                mp[incoming]++;
            }
            l++;
        }
        return ans;
        
    }
};