class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(arr[i]);
            else{
                if(st.top()>0 && arr[i]<0){
                    while(!st.empty()  && st.top()<abs(arr[i]) && st.top()>0){
                        st.pop();
                    }
                    if(st.empty()) st.push(arr[i]);
                    else if(st.top()==abs(arr[i])){
                        st.pop();
                    }
                    else if(st.top()<0) st.push(arr[i]);
                }
                else st.push(arr[i]);
            }

        }
        vector<int> ans(st.size());
        for(int i=ans.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};