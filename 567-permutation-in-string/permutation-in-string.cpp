class Solution {
public:
    bool compare(int hash[],int hash2[]){
        for(int i=0;i<26;i++){
            if(hash[i]!=hash2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int hash[26]={0};
        int hash2[26]={0};
        for(int i=0;i<s1.length();i++){
            hash[s1[i]-'a']++;
        }
        int win=s1.length();
        for(int i=0;i<s2.length();i++){
            hash2[s2[i]-'a']++;
            if(i-win>=0){
                hash2[s2[i-win]-'a']--;
            }
            if(compare(hash,hash2)) return true;

        }
        return false;
    }
};