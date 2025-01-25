class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> vec=nums;

        sort(vec.begin(),vec.end());
        map<int,int> numToGrp;
        map<int,list<int>> grpToList;
        int GRP=0;
        numToGrp[vec[0]]=GRP;
        grpToList[GRP].push_back(vec[0]);

        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                GRP++;
            }
            numToGrp[vec[i]]=GRP;
            grpToList[GRP].push_back(vec[i]);
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            // first we need to find which group this number belogs
            int currgrp=numToGrp[num];

            // now we need to find first member of this group
            int firstVal=*(grpToList[currgrp].begin());

            // we also need to remove the first element
            grpToList[currgrp].pop_front();
            ans[i]=firstVal;
        }
        return ans;
    }
};
// https://www.youtube.com/watch?v=_rQ4lJlI6nI