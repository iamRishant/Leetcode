class Solution {
public:
    int check(int mid,vector<int> piles,int hi){
        // int ele=piles[mid];
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=ceil(piles[i]/(mid*1.0));
            if(ans>hi) return 2;
        }
        // it means total sum is less than hour so we can go mmore back
        return 1;
        
    }
    int minEatingSpeed(vector<int>& piles, int hi) {
        int n=piles.size();
        // lets find the max range
        int maxi=0;
        for(int i=0;i<n;i++) maxi=max(piles[i],maxi);
        // now we need to find a value between 1 and maxi
        int l=1;
        int h=maxi;
        // let current ans be max
        int ans=h;
        while(h>=l){
            int mid=l+(h-l)/2;

            int val=check(mid,piles,hi);
            if(val==2) {
                // if the current mid cannot satisfy the timelimit then we will try to eat more at a time
                l=mid+1;
                }
            else {
                // if current k value is sufficient then we will go more back to check for any lesser value
                ans=min(mid,ans);
                h=mid-1;
                };
        }
        return ans;
    }
};