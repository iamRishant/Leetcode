class Solution {
public:
    bool check(int mid,vector<int> & piles,int h){
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i]+mid-1)/mid;//ceil value
            if(sum>h) return false;
        }
        if(sum<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=1e9;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};