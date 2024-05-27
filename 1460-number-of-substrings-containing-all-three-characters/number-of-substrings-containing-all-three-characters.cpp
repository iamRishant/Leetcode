class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.length()){
            if(s[r]=='a' || s[r]=='b' || s[r]=='c') mp[s[r]]++;

            
                while(mp.size()==3){
                    ans+=(s.length()-r-1);
                    ans++;
                    if(s[l]=='a' || s[l]=='b' || s[l]=='c') mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                }
            
            r++;
        }
        return ans;
    }
};