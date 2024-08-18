class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // light pole example
        map<int,int> mp;
        stack<int> st;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<nums2[i]) st.pop();
                if(st.empty()){
                    mp[nums2[i]]=-1;
                    st.push(nums2[i]);
                    continue;
                }
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        vector<int> ans;
        int m=nums1.size();
        for(int i=0;i<m;i++) ans.push_back(mp[nums1[i]]);
        return ans;

    }
};