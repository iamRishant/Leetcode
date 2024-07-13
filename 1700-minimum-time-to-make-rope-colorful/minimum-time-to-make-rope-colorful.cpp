class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(colors.size()==1) return 0;
        int ans=0;
        int mini=neededTime[0];
        
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                if(neededTime[i]>mini){
                    ans+=mini;
                    cout<<i<<" "<<mini<<" "<<ans<<endl;
                    mini=neededTime[i];

                }
                else{
                    ans+=neededTime[i];
                    cout<<i<<" "<<neededTime[i]<<" "<<ans<<endl;
                    // colors.erase(i,1);
                    // neededTime.erase(neededTime.begin()+i);
                    // i--;
                    colors[i]=colors[i-1];
                }
            }
            else mini=neededTime[i];
        }
        return ans;
    }
};