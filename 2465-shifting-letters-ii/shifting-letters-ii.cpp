class Solution {
public:
    string shifting(string s, vector<int>& suffix) {
        int n=suffix.size();
        
        
        string ans="";

        for(int i=0;i<s.length();i++){
            ans+=((s[i]-'a'+suffix[i])%26)+'a';
        }
        return ans;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> preFix(s.length()+1,0);
        for(int i=0;i<shifts.size();i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int val=shifts[i][2];
            if(val==0){
                preFix[start]-=1;
                preFix[end+1]+=1;
            }
            else{
                preFix[start]+=1;
                preFix[end+1]-=1;
            }
        }
        for(int i=1;i<preFix.size();i++) preFix[i]+=preFix[i-1];

        for(int i=0;i<preFix.size();i++){
            preFix[i]=preFix[i]%26;
            if(preFix[i]<0) preFix[i]+=26;
        }

        return shifting(s,preFix);
    
    }
};