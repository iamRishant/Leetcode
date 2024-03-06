class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size()-1;
        int n=matrix[0].size();
        while(high>=low){
            int mid=low+(high-low)/2;

            int start=matrix[mid][0];
            int end=matrix[mid][n-1];
            if(target>=start && target<=end){
                int index=lower_bound(matrix[mid].begin(),matrix[mid].end(),target)-matrix[mid].begin();
                if(index>=n) return false;
                else if(matrix[mid][index]!=target) return false;
                else return true;
            }
            else if(target>start) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};