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
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int l=1;
        int h=piles[n-1];
        int ans=h;
        while(h>=l){
            int mid=l+(h-l)/2;

            int val=check(mid,piles,hi);
            if(val==2) {
                l=mid+1;
                }
            else {
                ans=min(mid,ans);
                h=mid-1;
                };
        }
        return ans;
    }
};