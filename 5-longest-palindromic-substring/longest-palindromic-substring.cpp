class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int max_len=1;
        int n=s.size();
        int start=0;
        int end=0;
        for(int i=0;i<n-1;i++){
            int l,r;
            l=r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>max_len){
                start=l+1;
                end=r-1;
                max_len=len;
            }
        }
        for(int i=0;i<n-1;i++){
            int l,r;
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>max_len){
                start=l+1;
                end=r-1;
                max_len=len;
            }
        }
        return s.substr(start,max_len);
    }
};
// https://www.youtube.com/watch?v=ZJUGtWObroc