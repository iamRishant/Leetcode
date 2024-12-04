class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        
        int i=0;
        int j=0;
        
        while(i<n && j<m){
            char nextCharacter=(((str1[i]-'a')+1)%26)+'a';
            if(str1[i]==str2[j] || nextCharacter==str2[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(j==m) return true;
        return false;
    }
};