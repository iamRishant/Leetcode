class Solution {
public:
    static bool comp(vector<int> &first,vector<int> &second){
        if(first[0]==second[0]){
            return second[1]>first[1];
        }
        return second[0]>first[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int mini=intervals[0][1];
        int count=0;

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=mini){
                mini=intervals[i][1];
            }
            else{
                count++;
                mini=min(mini,intervals[i][1]);
            }
        }
        return count;
    }
};