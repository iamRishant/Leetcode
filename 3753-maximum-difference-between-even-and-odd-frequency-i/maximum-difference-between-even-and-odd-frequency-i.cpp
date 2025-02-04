class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();
        vector<int> hash(26,0);
        int evenMaxi=1e9;
        int oddMaxi=0;
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            // if(hash[s[i]-'a']%2==0) evenMaxi=max(evenMaxi,hash[s[i]-'a']);
            // else oddMaxi=max(oddMaxi,hash[s[i]-'a']);
        }
        for(int i=0;i<n;i++){
            // hash[s[i]-'a']++;
            if(hash[s[i]-'a']%2==0) evenMaxi=min(evenMaxi,hash[s[i]-'a']);
            else oddMaxi=max(oddMaxi,hash[s[i]-'a']);
        }
        return (oddMaxi-evenMaxi);
    }
};