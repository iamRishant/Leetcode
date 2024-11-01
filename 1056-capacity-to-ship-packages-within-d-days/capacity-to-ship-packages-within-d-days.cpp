class Solution {
public:
    bool check(int mid,vector<int> & weights,int days){
        int curr=0;
        int day=1;
        for(int i=0;i<weights.size();i++){
            curr+=weights[i];
            if(weights[i]>mid) return false;
            if(curr>mid){
                day++;
                curr=weights[i];
            }
            
        }

        if(day<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1e9;
        int high=0;
        int n=weights.size();

        for(int i=0;i<n;i++){
            low=min(low,weights[i]);
            high+=weights[i];
        }
        

        int ans=high;

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