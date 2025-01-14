class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st;
        int n=A.size();
        vector<int> ans;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(st.find(A[i])!=st.end()){
                st.erase(A[i]);
                count++;
            }
            else st.insert(A[i]);
            if(st.find(B[i])!=st.end()){
                count++;
                st.erase(B[i]);
            }
            else st.insert(B[i]);

            ans.push_back(count);

        }
        return ans;
    }
};