class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans(arr.size(),"");
        unordered_map<int,unordered_set<string>> mp;
        // lets get all substring and store in map
        for(int i=0;i<arr.size();i++){
            string s=arr[i];
            int sz=s.length();

            for(int j=0;j<sz;j++){
                for(int k=j;k<sz;k++){
                   string temp=s.substr(j,k-j+1);
                    mp[i].insert(temp);
                }
            }
        }

        for(int i=0;i<arr.size();i++){
            int minLen=INT_MAX;
            string curr="";

            for(auto tempString: mp[i]){
                // now we need to find tempString in other index
                bool flag=true;
                for(int j=0;j<arr.size();j++){
                    if(i==j) continue;

                    if(mp[j].contains(tempString)){
                        flag = false;
                        break;
                    }
                }

                // har ek subarray me check krne ke baad 
                if(flag){
                    if(tempString.length()<minLen){
                        minLen=tempString.length();
                        curr=tempString;
                    }
                    else if(tempString.length()==minLen && tempString<curr){
                        curr=tempString;
                    }
                }
            }
            ans[i]=curr;
        }
        return ans;
    }
};