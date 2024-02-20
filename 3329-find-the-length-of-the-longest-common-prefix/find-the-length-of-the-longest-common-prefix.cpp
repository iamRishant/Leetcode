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
        auto it1=s1.begin();
        auto it2=s2.begin();
        while(it1!=s1.end() && it2!=s2.end()){
            if((*it1)==(*it2)){
                int len=(*it1).length();
                ans=max(len,ans);
                it1++;
                it2++;
            }
            else if((*it1)>(*it2)) it2++;
            else it1++;

        }
        return ans;
    }
};