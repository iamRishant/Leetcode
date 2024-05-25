class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        // if(s==" ") return 1;
        int hash[26]={0};
        int right=0;
        int left=0;
        int ans=0;
        while(right!=s.length()){
            char curr=s[right];
            
            // cout<<curr<<" "<<index<<" "<<hash[index]<<endl;
            if((mp.find(curr)!=mp.end())){
                while(s[left]!=curr ){
                    mp.erase(s[left]);
                    left++;
                
                }
                mp.erase(curr);
                left++;
                cout<<left<<" "<<endl; 
                
            }
            else{
                // hash[index]=1;
                mp[curr]=1;
                ans=max(ans,right-left+1);
                right++;
                // cout<<ans<<" "<<endl;
            }
        }
        return ans;
    }
};