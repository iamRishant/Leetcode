class Solution {
public:
    bool check(long long mid, int k, int r,vector<int> stations){
        int n=stations.size();
        long long sum=0;
        for(int i=0;i<r;i++) sum+=stations[i];

        for(int i=0;i<n;i++){
            // moving window ahead
            if(i+r<n) sum+=stations[i+r];
            //piche wale ko removing
            if(i-r-1>=0) sum-=stations[i-r-1];

            // now checking current power of station (sum is current power)
            if(sum<mid){
                if(mid-sum>k) return false;//we dont have additional stations
                else{
                    //it means we have more req station 
                    //we will plant that station fartherst so that it can power more citits
                    stations[min(n-1,i+r)]+=(mid-sum);
                    k-=(mid-sum);

                    // now the power of the window is mid
                    sum=mid;
                }
            }
        }
        // if all satisfied 
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long high=k;
        long long low=0;
        long long ans=-1;
        int n=stations.size();
        for(int i=0;i<n;i++){
            high+=stations[i];
        }

        
       
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid,k,r,stations)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;


        // return 0;
    }
};