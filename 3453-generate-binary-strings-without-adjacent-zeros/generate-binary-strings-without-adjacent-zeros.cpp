class Solution {
public:
    void solve(int index,int n,vector<string> &ans,string s){
        if(index==n){
            ans.push_back(s);
            return;
        }

        // if last character is 1 we can take 0 or 1 
        // else we can take only 1 in next
        if(s=="" || s.back()=='1'){
            solve(index+1,n,ans,s+'1');
            solve(index+1,n,ans,s+'0');
        }
        else{
            solve(index+1,n,ans,s+'1');
        }

        return;
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(0,n,ans,"");
        return ans;
    }
};