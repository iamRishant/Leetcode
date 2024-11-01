class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(ans!="" && s[i]==ans.back()) {ans+=s[i];count++;}
            else {ans+=s[i];count=1;}
            if(count==2){
                while(i<n && s[i]==ans.back()){
                    i++;
                }
                if(i==n) break;
                else ans+=s[i];
                count=1;
            }
        }
        return ans;
    }
};