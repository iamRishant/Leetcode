class Solution {
public:
    string robotWithString(string s) {
        int n=s.length();
        vector<char> preComputation(n);

        preComputation[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            preComputation[i]=min(s[i],preComputation[i+1]);
        }

        int i=0;
        string t="";
        string ans="";

        while(i<n){
            t+=s[i];
            char minChar=i+1<n ? preComputation[i+1]: s[i];
            while(t!="" && t.back()<=minChar){
                ans+=t.back();
                t.pop_back();
            }
            i++;
        }  
        while(!t.empty()){
            ans+=t.back();
            t.pop_back();
        }
        return ans;
    }
};