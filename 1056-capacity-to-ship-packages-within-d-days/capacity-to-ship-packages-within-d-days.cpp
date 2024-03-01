class Solution {
public:
    int check(int mid,vector<int> &weights,int days){
        int n=weights.size();
        int temp=mid;
        int count=0;
        // int i=1;
        for(int i=0;i<n;i++){
            temp=temp-weights[i];
            // cout<<temp<<" ";
            if(temp<0){
                count++;
                temp=mid-weights[i];
                if(temp<0) return 1;
            }
        }
        if(temp>=0) count++;
        
        if(count<=days) return 0;
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        vector<int> preFix(n+1,0);

        for(int i=1;i<=n;i++){
            preFix[i]=weights[i-1]+preFix[i-1];
        }
        int l=preFix[0];
        int h=preFix[n];
        int ans=h;
        while(h>=l){
            int mid=l+(h-l)/2;

            int val=check(mid,weights,days);
            if(val==0) {h=mid-1; ans=min(ans,mid);}
            else l=mid+1;
        }

        return ans;

    }
};