class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // divide the whole process into 3 parts
        // first push all the interval which are smaller 
        // then update the merged interval 
        //last push all the remaining

        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;

        // step1
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // step2
        // here we will update the interval , we will check number of interval which
        // are intersecting with the interval and just merge them
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        // step3 yha se aage koi over lap nhi kar rha hoga
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};