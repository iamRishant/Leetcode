class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // int sum=0;
        int maxi=-1;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            // sum+=arr[i];
            maxi=max(arr[i],maxi);
            // int total=i*(i+1)/2;
            if(i==maxi) ans++;
        }

        return ans;
    }
};