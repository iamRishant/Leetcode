class Solution {
public:
    vector<vector<int>> dp;
    unordered_set<int> st;
    int n,m;
    int solve(int i,int j,string &source,string &pattern){
        if(i==n){
            if(j==m) return 0;
            return -1e7;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int op1=-1e7;
        int op2=-1e7;
        int op3=-1e7;
        op1=solve(i+1,j,source,pattern);// we are not deleting anything
        if(st.find(i)!=st.end()){
            // it means index is present in the set it means we can delete
            op2=1+solve(i+1,j,source,pattern);
        }
        if(source[i]==pattern[j]) op3=solve(i+1,j+1,source,pattern);

        return dp[i][j]=max(op1,max(op2,op3));
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
         n=source.size();
         m=pattern.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        // set<int> st;
        for(auto &it: targetIndices) st.insert(it);
        return solve(0,0,source,pattern);
    }
};