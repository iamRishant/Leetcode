class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(ans.back()[1]>=start){
                int nstart=ans.back()[0];
                int nend=ans.back()[1];
                ans.pop_back();
                end=max(end,nend);

                ans.push_back({nstart,end});
            }
            else{
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};