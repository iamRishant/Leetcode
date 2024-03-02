class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // o(logn)
        int n=arr.size();
        int l=0;
        int h=n-1;

        while(h>=l){
            int mid=l+(h-l)/2;

            int missing=arr[mid]-(mid+1);//jo uss index par hai - jo uss index par hona chahiye
            if(missing<k) l=mid+1;
            else h=mid-1;
        }

        // now we ar[h] will be on that place where after which the kth missing elemtn will be
        // there fore ans will be arr[h]+more what is this more 
        // more is k-missing number what is missing number
        // arr[h]-(h+1) same as line 12
        // ther for after solving equation we get high +1 +k or low+k

        return h + 1 + k;
         

    }
};