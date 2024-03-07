class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        int n=mat.size();
        int m=mat[0].size();
        while(high>=low){
            int mid=low+(high-low)/2;

            // lets find max in this column
            int row=-1;
            int col=-1;
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    row=i;
                    col=mid;
                }
            }
            // note top and bottom se greater hi hai
            // we just have to left and right
            int left=-1;
            int right=-1;
            if(col-1>=0) left=mat[row][col-1];
            if(col+1<m) right=mat[row][col+1];
            if(mat[row][col]>left && mat[row][col]>right) return {row,col};
            else if(mat[row][col]<left) high=mid-1;
            else low=mid+1;
        }
        return {0,0};
    }
};