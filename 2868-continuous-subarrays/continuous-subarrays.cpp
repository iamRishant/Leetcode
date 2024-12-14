class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // this is an nlogn solution becoz of set we need to use monotonic queue 
        // to reduce the extra logn operaion of contant operatio
        long long ans=0;
        set<pair<int,int>> st;
        // for(int i=0;i<nums.size();i++) st.insert({nums[i],i});
        int n=nums.size();
        int left=0;
        for(int i=0;i<n;i++){
            st.insert({nums[i],i});
            int maxi=(st.rbegin()->first);
            int mini=(st.begin()->first);
            while(maxi-mini>2){
                st.erase({nums[left],left});
                left++;
                maxi=(st.rbegin()->first);
                mini=(st.begin()->first);
            }
            ans+=(i-left+1);
        }
        return ans;
    }
};