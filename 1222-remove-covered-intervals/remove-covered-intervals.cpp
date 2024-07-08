class Solution {
public:
    static bool comp(vector<int> &first,vector<int> &second){
        if(first[0]==second[0]) return first[1]>second[1];
        return first[0]<second[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        int maxi=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]<=maxi) count++;
            maxi=max(intervals[i][1],maxi);
        }
        return intervals.size()-count;
    }
};