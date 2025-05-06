class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int n, int startVal, int rowStart, int colStart, int size) {
        if (size == 1) {
            ans[rowStart][colStart] = startVal;
            return;
        }
        
        int halfSize = size / 2;
        int quadrantSize = halfSize * halfSize;
        
       
        solve(n, startVal + 3 * quadrantSize, rowStart, colStart, halfSize);
        
        
        solve(n, startVal, rowStart, colStart + halfSize, halfSize);
        
        
        solve(n, startVal + quadrantSize, rowStart + halfSize, colStart + halfSize, halfSize);
        
        
        solve(n, startVal + 2 * quadrantSize, rowStart + halfSize, colStart, halfSize);
    }
    
    vector<vector<int>> specialGrid(int n) {
        int size = pow(2, n);
        ans.assign(size, vector<int>(size, 0));
        
        solve(n, 0, 0, 0, size);
        return ans;
    }
};