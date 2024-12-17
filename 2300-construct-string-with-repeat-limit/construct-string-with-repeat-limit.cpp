class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int> st;
        int n=s.length();

        for(int i=0;i<n;i++){
            st[s[i]]++;
        }
        // set<pair<char,int>> st;
        // for(auto it: mp){
        //     st.insert({it.first,it.second});
        // } 
        
        string ans="";

        while(!st.empty()){
            auto tp=*st.rbegin();
            st.erase(tp.first);

            if(tp.second<=repeatLimit){
                int limit=tp.second;
                while(limit--){
                    ans+=tp.first;
                }
            }
            else{
                int limit=repeatLimit;
                while(limit--){
                    ans+=tp.first;
                }
                string second="";

                if(!st.empty()){
                    auto stp=*st.rbegin();
                    st.erase(stp.first);

                    second+=stp.first;

                    if(stp.second-1>0){
                        st[stp.first]=stp.second-1;
                        // st.insert({stp.first,stp.second-1});
                    }
                }
                // st.insert({tp.first,tp.second-repeatLimit});
                st[tp.first]=tp.second-repeatLimit;
                if(second=="") return ans;
                else ans+=second;

            }

        }

        return ans;
    }
};