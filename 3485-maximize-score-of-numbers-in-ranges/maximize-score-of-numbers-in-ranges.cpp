class Solution {
public:
    bool check(long long mid,vector<int> & start, int d){
        int prev=start[0];
        for(int i=1;i<start.size();i++){
            long long next=max(prev+mid,(long long)start[i]);
            if(next>start[i]+d) return false;
            prev=next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n=start.size();
        long long low=0;
        long long high=start[n-1]+d-start[0];
        int ans=0;
        while(high>=low){
            long long mid=(high+low)/2;

            bool flag=check(mid,start,d);
            if(flag) {ans=mid;low=mid+1;}
            else high=mid-1;
        }
        return ans;
    }
};