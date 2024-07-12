class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start=0;
        int end=tokens.size()-1;
        int ans=0;
        int maxi=0;
        while(start<=end){
            while(start<=end && power>=tokens[start]  ){
                ans++;
                power-=tokens[start];
                start++;
                maxi=max(ans,maxi);

            }
            if(start<=end && power<tokens[start] && ans>0  ){
                ans--;
                power+=tokens[end];
                end--;

            }
            if(start>end) break;
            if(ans==0 && power<tokens[start]) break;
        }
        return maxi;
    }
};