class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0;
        int last=1;
        for(int i=0;i<meetings.size();i++){
            int s=meetings[i][0];
            int e=meetings[i][1];
            if(s>last) ans+=(i==0)? (s-last) : (s-last-1);
            last=max(e,last);
        }
        if(days>last){
            ans+=(days-last);
        }
        return ans;
        
    }
};