class Solution {
public:
    int minimumLength(string s) {

        vector<int> left(26,0);
        vector<int> right(26,0);
        for(int i=0;i<s.length();i++){
            right[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<s.length();i++){
            right[s[i]-'a']--;
            if(left[s[i]-'a'] && right[s[i]-'a']){
                left[s[i]-'a']--;
                right[s[i]-'a']--;
            }
            else{
                count++;
            }
            left[s[i]-'a']++;
        }
        return count;
    }
};