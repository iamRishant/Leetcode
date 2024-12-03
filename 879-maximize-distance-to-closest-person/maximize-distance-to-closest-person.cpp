class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev=0;
        int n=seats.size();
        int ans=0;
        int count=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==0) count++;
            else{
                if(count>maxi){
                    maxi=count;
                    if(seats[prev]==0) ans=i;
                    else ans=max(ans,((count+1)/2));
                }
                count=0;
                prev=i;
            }
        }
        if(count>ans){
                    return n-1-prev;
                }

        return ans;
    }
};