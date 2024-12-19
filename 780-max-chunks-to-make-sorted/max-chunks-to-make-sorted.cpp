class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int total=i*(i+1)/2;
            if(sum==total) ans++;
        }

        return ans;
    }
};