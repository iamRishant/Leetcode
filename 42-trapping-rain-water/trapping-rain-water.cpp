class Solution {
public:
    int trap(vector<int>& height) {
        // total+=(min(leftMax,rightMax)-arr[i])
        int n=height.size();
        vector<int> preFixMax(n,0);
        vector<int> sufFixMax(n,0);
        preFixMax[0]=height[0];
        sufFixMax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            preFixMax[i]=max(preFixMax[i-1],height[i]);
            sufFixMax[n-i-1]=max(sufFixMax[n-i],height[n-i-1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=preFixMax[i];
            int r=sufFixMax[i];
            if(height[i]<l && height[i]<r){
                ans+=(min(l,r)-height[i]);
            }
        }

        return ans;

    }
};