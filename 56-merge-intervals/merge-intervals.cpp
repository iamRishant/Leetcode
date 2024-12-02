class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
            }
            else{
                auto prev=ans.back();
                if(intervals[i][0]<=prev[1]){
                    vector<int> temp(2);
                    temp[0]=min(prev[0],intervals[i][0]);
                    temp[1]=max(prev[1],intervals[i][1]);
                    ans.pop_back();
                    ans.push_back(temp);
                }
                else ans.push_back(intervals[i]);
            }
        }
            return ans;
    }
};