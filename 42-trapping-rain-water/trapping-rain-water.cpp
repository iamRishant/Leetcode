class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int n=height.size();
        int r=n-1;
        int lmax=height[l];
        int rmax=height[r];
        int ans=0;

        while(l<r){
            if(lmax<rmax){//since right side is greater we need only left side 
                l++;
                lmax=max(lmax,height[l]);//calculating the prefix 
                ans+=(lmax-height[l]);
            }
            else{
                r--;
                rmax=max(rmax,height[r]);// same calculating the suffix
                ans+=(rmax-height[r]);
            }
        }
        return ans;

    }
};