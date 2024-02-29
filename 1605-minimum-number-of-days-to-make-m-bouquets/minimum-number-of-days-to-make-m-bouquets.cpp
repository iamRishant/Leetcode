class Solution {
public:
    int check(int mid,vector<int> &arr,int m,int k){
        int ans=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid) count++;
            else{
                ans+=((count)/k);
                count=0;
            }
        }
        ans+=(count/k);
        if(ans>=m) return 0;
        return 1;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        if(long(m)*k>n) return -1;
        int l=INT_MAX;
        int h=-1;
        for(int i=0;i<n;i++){
            l=min(arr[i],l);
            h=max(arr[i],h);
        }
        int ans=h;
        // now we got thee range we have to find the correct op
        while(h>=l){
            int mid=l+(h-l)/2;
            int val=check(mid,arr,m,k);
            cout<<"val "<<val<<" ";
            if(val==0){
                ans=min(mid,ans);
                h=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};