class Solution {
public:
    string addSpaces(string S, vector<int>& spaces) {
        string s="";

        int n=S.length();
        int m=spaces.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j<m && i==spaces[j]){
                // s=s+' ' this operation is o(n) coz it creates new string
                s+=' ';//this is o(1)
                j++;
            }
            s+=S[i];
        }
        return s;
    }
};