class Solution {
public:
    int maxOperations(string s) {
        int c1=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                c1++;
            }
            else{
                ans+=c1;
                while(s[i]=='0') i++;
                i--;
            }
        }
        return ans;
    }
};