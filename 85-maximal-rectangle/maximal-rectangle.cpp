class Solution {
public:
    vector<int> getNSL(vector<int> & arr, int n) {
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop(); // Move this out of else
        if (st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(i);  // Push the current index onto the stack
    }
    return res;
}

vector<int> getNSR(vector<int> & arr, int n) {
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop(); // Move this out of else
        if (st.empty()) res[i] = n;
        else res[i] = st.top();
        st.push(i);  // Push the current index onto the stack
    }
    return res;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> NSL=getNSL(heights,n);
        vector<int> NSR=getNSR(heights,n);

        int maxi=-1e9;
        for(int i=0;i<n;i++){
            int ls=i-NSL[i];
            int rs=NSR[i]-i;
            // cout<<ls<<" "<<rs<<endl;
            int number=ls+rs-1;
            int val=number*heights[i];
            // cout<<val<<endl;
            maxi=max(maxi,val);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<int> prev(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    prev[j]=0;
                }
                else prev[j]+=(matrix[i][j]-'0');
            }
            // for(int k=0;k<m;k++) cout<<prev[k]<<" ";
            // cout<<endl;
            maxi=max(maxi,largestRectangleArea(prev));
        }
        return maxi;
    }
};