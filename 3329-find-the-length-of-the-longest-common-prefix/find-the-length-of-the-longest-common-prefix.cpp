class Solution {
public:
    set<string> allPrefix(vector<int> arr1){
        set<string> ans;
        for(auto ele:arr1){
            string s=to_string(ele);
            string temp="";
            for(auto x:s){
                temp+=x;
                ans.insert(temp);
            }
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> s1=allPrefix(arr1);
        set<string> s2=allPrefix(arr2);

        int ans=0;
        for(auto ele:s1){
            if(s2.find(ele)!=s2.end()){
                int len=ele.length();
                ans=max(ans,len);
            }
        }
        return ans;
    }
};