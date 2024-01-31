class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> ans(temp.size(),0);
        for(int i=temp.size()-1;i>=0;i--){
            while(!st.empty() && temp[i]>=temp[st.top()]) st.pop();
            if(st.empty()==true) ans[i]=0;
            else {
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};