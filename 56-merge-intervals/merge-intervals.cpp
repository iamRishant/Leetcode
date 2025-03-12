class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(ans.back()[1]<intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else{
                auto back=ans.back();
                ans.pop_back();
                back[0]=min(back[0],intervals[i][0]);
                back[1]=max(back[1],intervals[i][1]);
                ans.push_back(back);
            }
        }
        return ans;
    }
};