class Solution {
public:
// NSL agar left me puch rha to left se travere kro agar NSR right se puch rha to right se travere kro same for NGR and NGL
    vector<int> getNSL(vector<int> &arr,int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){// = isiliye ki ek case me duplicate include krenge and doosre me nhi krenge
                    st.pop();
                }
                res[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> getNSR(vector<int> &arr,int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){// = isiliye ki ek case me duplicate include krenge and doosre me nhi krenge
                    st.pop();
                }
                res[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> NSL=getNSL(arr,n);
        vector<int> NSR=getNSR(arr,n);

        long long ans=0;
        long long mod=1e9+7;

        for(int i=0;i<n;i++){
            long long ls=i-NSL[i];
            long  long rs=NSR[i]-i;
            long long total=(ls*rs)%mod;
            total=total*arr[i];
            total=total%mod;
            ans+=total;
            ans=ans%mod;
        }
        return ans;
    }
};