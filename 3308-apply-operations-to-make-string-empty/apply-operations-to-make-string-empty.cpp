class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char,int> mp;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
        }

        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(mp[s[i]]==maxi){
                ans+=s[i];
                mp[s[i]]--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};