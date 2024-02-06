class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        for(int i=1;i<=n;i++){
            int d=k*i;
            if(d>=n) return i;
            bool ok=true;
            for(int j=d;j<n;j++){
                if(word[j]!=word[j-d]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                // it means no mismatch found
                return i;
            }
        }
        return 0;
    }
};