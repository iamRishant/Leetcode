class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // using 2 arrays but o(n) complexity
        vector<vector<int>> ans;
        int n=intervals.size();
        int flag=1;
        // put new interval in new position
        for(int i=0;i<n;i++){
            if(flag&&newInterval[0]<intervals[i][0]){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                flag=0;
            }
            else ans.push_back(intervals[i]);
        }
        if(flag) ans.push_back(newInterval);
        // now simply apply merge intervals;
        vector<vector<int>> finalAns;
        for(int i=0;i<ans.size();i++){
            if(finalAns.size()==0){
                finalAns.push_back(ans[i]);
            }
            else{
                auto prev=finalAns.back();
                // finalAns.pop_back();
                if(prev[1]<ans[i][0]){
                    finalAns.push_back(ans[i]);
                    continue;
                }
                else{
                    finalAns.pop_back();
                    vector<int> temp(2);
                    temp[0]=min(prev[0],ans[i][0]);
                    temp[1]=max(prev[1],ans[i][1]);
                    finalAns.push_back(temp);
                }
            }
        }
            return finalAns;
            // return ans;
    }
};