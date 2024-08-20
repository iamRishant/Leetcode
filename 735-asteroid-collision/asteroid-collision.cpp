class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            if(st.empty() || (st.top()<0 && arr[i]<0) || arr[i]>0) st.push(arr[i]);
            else {
                while(!st.empty() && st.top()< abs(arr[i]) && st.top()>0) st.pop();
                // iske baad ya to stack empty ya == ya >
                
                if(st.empty()){
                    st.push(arr[i]);
                    continue;
                }
                if(st.top()==abs(arr[i])){
                    st.pop();
                    continue;
                }
                if(st.top()>abs(arr[i])) continue;
                st.push(arr[i]);
                
            }
        }
         n=st.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};