class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        for(int i=0;i<palindrome.size()/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        int n=palindrome.size()-1;
        palindrome[n]='b';
        return palindrome;
    }
};