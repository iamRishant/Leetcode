class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (j >= i) {
            swap(s[i++], s[j--]);
        }
        return s;
    }

    int longestPalindrome(vector<string>& words) {
        int maxi = 0;
        string maxOddPalindrome;
        map<string, int> mp;

        // Count the frequency of each word
        for (auto& word : words) {
            mp[word]++;
        }

        // Find the palindrome with the maximum odd frequency
        
        bool odd=true;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            if(mp[words[i]]>0){

            string rev = reverseString(words[i]);
            if(mp[rev]>0){
                if(rev==words[i]){
                    //so now it can be 1 or more than 1 if it is one we can only use one
                    if(mp[rev]==1 && odd){
                        odd=false;
                        ans+=2;
                        mp[rev]--;
                    }
                    else if(mp[rev]>1){
                        ans+=4;
                        mp[rev]--;
                        mp[rev]--;
                    }
                }
                else{
                    mp[words[i]]--;
                    mp[rev]--;
                    ans+=4;
                }
            }
            }
        }

        return ans;
    }
};
