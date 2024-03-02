class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int temp=k;
        // for first element
        // int difff=arr[0]-0;
        // difff--;
        // if(difff>=k) return temp;
        // else k=k-difff;

        if(k<arr[0]) return k;
        else k=k-(arr[0]-1);
        //-------------------------+
        for(int i=1;i<n;i++){
            int diff=arr[i]-arr[i-1];
            if(diff>1){
                diff--;
                if(diff>=k){
                    return arr[i-1]+k;
                }
                else{
                    k=k-diff;
                }
            }
        }
        return arr[n-1]+k;
    }
};