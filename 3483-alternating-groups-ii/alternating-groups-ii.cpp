class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int n=colors.size();
        int maxlength=1;
        for(int i=1;i<=n-1+k-1;i++){
            if(colors[i%n]!=colors[(i-1)%n]){
                maxlength++;
            }
            else{
                maxlength=1;
            }
            if(maxlength>=k){
                ans++;
            }
        }
        return ans;
    }
};