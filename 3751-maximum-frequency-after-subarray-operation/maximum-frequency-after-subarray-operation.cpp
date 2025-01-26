class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans=0;
        set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==k) ans++;
            st.insert(nums[i]);
        }
        
        int maxi=0;
        for(auto it: st){
            int curr=0;
            for(int i=0;i<n;i++){
                if(nums[i]==k) curr--;
                else if(nums[i]==it) curr++;

                if(curr<0) curr=0;
                maxi=max(curr,maxi);
            }
        }
        return ans+maxi;
    }
};
// https://www.youtube.com/watch?v=OZwYStLC8J4