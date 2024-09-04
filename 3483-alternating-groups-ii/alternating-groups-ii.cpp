class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int l=0;
        int r=1;
        int ans=0;
        while(l<n && r<n+k-1){
            int currIndex=r%n;
            int prevIndex=(r-1+n)%n;
            if(colors[prevIndex]==colors[currIndex]){
                l=r;
            }
            
            if(r-l+1>=k){
                ans++;
            }
            r++;
        }
        return ans;
    }
};