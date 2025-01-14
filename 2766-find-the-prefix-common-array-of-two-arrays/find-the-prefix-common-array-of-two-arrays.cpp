class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> hash(51,0);
        int n=A.size();
        vector<int> ans;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(hash[A[i]]){
                hash[A[i]]=0;
                count++;
            }
            else hash[A[i]]=1;
            if(hash[B[i]]){
                count++;
                hash[B[i]]=0;
            }
            else hash[B[i]]=1;

            ans.push_back(count);

        }
        return ans;
    }
};