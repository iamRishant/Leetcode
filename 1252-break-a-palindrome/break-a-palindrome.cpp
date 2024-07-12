class Solution {
public:
    string breakPalindrome(string palindrome) {
        // i need to find smallest character other than a then just convert it to a
        int index=-1;
        int n=palindrome.size()/2;
        char minchar='z'+1;
        if(palindrome.size()==1) return "";
        for(int i=0;i<n;i++){
            if(palindrome[i]!='a'){
                // cout<<minchar<<endl;
                if(minchar>palindrome[i]){
                    minchar=palindrome[i];
                    index=i;
                    break;
                }
            }
        }

        string ans="";
        if(index==-1){
            // it means only a is there
            for(int i=0;i<palindrome.size()-1;i++) {
                ans+=palindrome[i];
            }
            ans+='b';
        }
        else{
            for(int i=0;i<palindrome.size();i++){
                if(i==index){
                    ans+='a';
                }
                else ans+=palindrome[i];
            }
        }
            return ans;
    }
};