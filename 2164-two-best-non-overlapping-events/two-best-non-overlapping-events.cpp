class Solution {
public:
    int solve(int idx,int prev,vector<vector<int>> &events,int n,int k){
        if(idx==n) return 0;
        if(k==0) return 0;

        int pick=0;
        int notPick=0;
        if(events[idx][0]>prev) pick=events[idx][2]+solve(idx+1,events[idx][1],events,n,k-1);
        notPick=solve(idx+1,prev,events,n,k);
        

        return max(pick,notPick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int maxi=0;
        vector<int> maxArray(n,0);
        maxArray[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            maxArray[i]=max(events[i][2],maxArray[i+1]);
        }

        for(int i=0;i<n;i++){
            int curr=events[i][2];
            int aage=0;
            vector<int>ans={events[i][1],INT_MAX,INT_MAX};
            int idx=upper_bound(events.begin(),events.end(),ans)-events.begin();
            // while(idx<n){
            //     aage=max(aage,events[idx][2]);
            //     idx++;
            // }
            if(idx<n) aage=maxArray[idx];
            maxi=max(maxi,curr+aage);
        }
    return maxi;
    }
};