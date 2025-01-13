class Solution {
public:
    bool check(int mid,vector<int> & weights,int days){
        int day=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                sum=weights[i];
                day++;
            }
        }
        if(day>days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=0;
        for(int i=0;i<weights.size();i++) maxi=max(weights[i],maxi);
        int low=maxi;
        int high=accumulate(weights.begin(),weights.end(),0);

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};