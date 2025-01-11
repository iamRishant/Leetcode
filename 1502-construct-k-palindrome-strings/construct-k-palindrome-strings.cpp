class Solution {
public:
    bool canConstruct(string s, int k) {
        int len=s.length();
        if(len-k<0) return false;
        if(len==k) return true;

        map<char,int> mp;
        for(int i=0;i<len;i++) mp[s[i]]++;
        int odd=0;
        for(auto it:mp) if(it.second%2!=0) odd++;
        if(odd>k) return false;
        return true;

    }
};