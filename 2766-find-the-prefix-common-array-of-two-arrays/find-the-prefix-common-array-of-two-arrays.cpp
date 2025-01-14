class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st;
        int n=A.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            st.insert(B[i]);
            int count=0;
            for(int j=0;j<=i;j++){
                if(st.find(A[j])!=st.end()) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};