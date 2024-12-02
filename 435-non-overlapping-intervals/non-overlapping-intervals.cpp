class Solution {
public:
    static bool comp(vector<int> & first, vector<int> &second){
        if(first[0]==second[0]) return first[1]<second[1];

        return first[0]<second[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);

        int count=0;
        int mini=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<mini){
                // when we get overlapping then now we have to decide ki 
                // konsa wlae ko remove krna hai
                //to thoda sochne par pta chalega ki 
                // jiska range jyda usko htao kyuki wo jyda logo se overlap krega
                //to jiska range minimum hai usko rakhenge and and jiska jyda hai usko hta kar 
                // count++ kr denge
                count++;
                mini=min(intervals[i][1],mini);
                
            }
            else mini=intervals[i][1];
        }
        return count;
        
    }
};