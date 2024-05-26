class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0;
        int r=0;
        int hash[26]={0};
        int maxf=0;
        int ans=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(hash[s[r]-'A'],maxf);
            int len=r-l+1;
            if(len-maxf>k){
                hash[s[l]-'A']--;
                maxf=0;
                l++;
            }
            if(len-maxf<=k){
                ans=max(ans,len);
            }
            r++;

        }
        return ans;
    }
};