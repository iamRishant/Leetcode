class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            stack<int> s;
            for (int k = 0; k <= n; k++) {
                while (!s.empty() && (k == n || height[s.top()] >= height[k])) {
                    int h = height[s.top()];
                    s.pop();
                    int w = k - (s.empty() ? 0 : s.top() + 1);
                    maxArea = max(maxArea, h * w);
                }
                s.push(k);
            }
        }
        
        return maxArea;
    }
};