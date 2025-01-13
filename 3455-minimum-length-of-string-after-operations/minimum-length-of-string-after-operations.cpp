class Solution {
public:
    int minimumLength(string s) {
        vector<int> hash(26,0);
        int n=s.length();
        int cnt=0;

        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            if(hash[s[i]-'a']==3) {hash[s[i]-'a']=1; cnt+=2;}
        }
        return n-cnt;
    }
};