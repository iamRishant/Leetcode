class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        // first jo jo overlap nhi kar rha usko as it it daal do
        int i=0;
        int n=intervals.size();
        while(i<n && newInterval[0]>intervals[i][1]){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        // now jo overlapping hai usko merge krdo
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        // when we merged the over lapping thiing we will just add it 
        ans.push_back(newInterval);
        // after that just simply add remaining
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        

        return ans;

    }
};