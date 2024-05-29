class Solution {
public:
    string minWindow(string s, string t) {
        int sIndex=-1;
        int minLen=1e9;
        int l=0;
        int r=0;
        int count=0;
        map<char,int> mp;
        for(int i=0;i<t.size();i++) mp[t[i]]++;
        while(r<s.length()){
            if(mp[s[r]]>0) count++;
            mp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    sIndex=l;
                }

                    mp[s[l]]++;
                    if(mp[s[l]]>0) count--;
                    l++;
                
            }
                r++;
        }
        return sIndex==-1 ? "": s.substr(sIndex,minLen);
    }
};