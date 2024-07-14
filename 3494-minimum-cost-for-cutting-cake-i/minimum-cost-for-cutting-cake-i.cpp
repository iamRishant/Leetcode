class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int vb=1,hb=1,i=0,j=0;
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());
        int ans=0;
        while(i<m-1 && j<n-1){
            if(horizontalCut[i]<=verticalCut[j]){
                ans+=(verticalCut[j]*hb);
                j++;
                vb++;
            }
            else {
                ans+=(horizontalCut[i]*vb);
                i++;
                hb++;
            }
        }
        while(i<m-1){
                ans+=(horizontalCut[i]*vb);
                i++;
                hb++;
        }
        while(j<n-1){
                ans+=(verticalCut[j]*hb);
                j++;
                vb++;
        }
        return ans;
    }
};