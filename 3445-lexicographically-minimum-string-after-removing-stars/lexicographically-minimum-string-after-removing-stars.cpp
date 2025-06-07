class Solution {
public:
    string clearStars(string s) {
        int minChar=s[0];
        int minIdx=0;
        int n=s.length();
        set<pair<char,int>> st;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.insert({s[i],-i});
            }
            if(s[i]=='*'){
                if(st.empty()) continue;
                auto it=st.begin();
                int idx=-1*(it->second);
                // cout<<it->first<<" "<<it->second<<endl;
                st.erase(*it);
                s[idx]='*';
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='*') ans+=s[i];
        }
        return ans;
    }
};