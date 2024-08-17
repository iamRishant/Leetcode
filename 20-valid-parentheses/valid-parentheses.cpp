class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
             char tp=st.top();
             if(st.empty()==true) return false;
             else if((tp=='(' && s[i]==')') || (tp=='{' && s[i]=='}') || tp=='[' && s[i]==']') st.pop();
             else return false;
            }
        }
        if(st.size()>0) return false;
        return true;
    }
};