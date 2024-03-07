class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int index=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(index<0 || index>=m || matrix[i][index]!=target) continue;
            else return true;
        }
        return false;
    }
};