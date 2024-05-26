class Solution {
public:
    int characterReplacement(string s, int k) {
        // brute force creating all the substring len-maxf

    int ans=0;
    for(int i=0;i<s.length();i++){
    int maxf=0;
    int hash[26]={0};
        for(int j=i;j<s.length();j++){
            hash[s[j]-'A']++;
            maxf=max(maxf,hash[s[j]-'A']);
            int changes=(j-i+1)-maxf;//len-maxf
            if(changes<=k){
                ans=max(ans,j-i+1);
            }
            else break;
        }
    }
    return ans;
    }
};