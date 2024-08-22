class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int nsr=i;
                    int val=heights[st.top()];
                    st.pop();
                    int nsl=st.empty()?-1:st.top();
                    maxi=max(maxi,(nsr-nsl-1)*val);
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int nsr=n;
            int val=heights[st.top()];
            st.pop();
            int nsl=st.empty()?-1:st.top();
            maxi=max(maxi,(nsr-nsl-1)*val);
        }
        return maxi;
    }
};