class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        vector<int> preFix(cp.size(),0);
        vector<int> postFix(cp.size(),0);
        preFix[0]=cp[0];
        for(int i=1;i<cp.size();i++){
            preFix[i]=preFix[i-1]+cp[i];
            // cout<<preFix[i]<<" ";
        }
        // cout<<endl;
        postFix[0]=cp[n-1];
        int j=1;
        for(int i=n-2;i>=0;i--){
            postFix[j]=postFix[j-1]+cp[i];
            // cout<<postFix[j]<<" ";
            j++;
            
        }
        int ans=0;
        int l=k-1;
        int r=-1;
        // k++;
        for(int i=0;i<=k;i++){
            if(r==-1){
                ans=preFix[l];
            }
            else if(l==-1){
                ans=max(ans,postFix[r]);
            }
            else{
                ans=max(preFix[l]+postFix[r],ans);
            }
            r++;
            l--;
        }
        return ans;

    }
};