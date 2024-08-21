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
            cout<<ls<<" "<<rs<<endl;
            int number=ls+rs-1;
            int val=number*heights[i];
            // cout<<val<<endl;
            maxi=max(maxi,val);
        }
        return maxi;
    }
};