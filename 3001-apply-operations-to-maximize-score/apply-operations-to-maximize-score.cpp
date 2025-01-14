class Solution {
public:
    vector<int> getNGL(vector<int> &ps){
        stack<int> st;
        int n=ps.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;
                st.push(i);
            }
            else{
                while(!st.empty() && ps[st.top()]<ps[i]) st.pop();

                if(st.empty()) res[i]=-1;
                else res[i]=st.top();

                st.push(i);
            }
        }
        return res;
    }

    vector<int> getNGR(vector<int> &ps){
        stack<int> st;
        int n=ps.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;
                st.push(i);
            }
            else{
                while(!st.empty() && ps[st.top()]<=ps[i]) st.pop();

                if(st.empty()) res[i]=n;
                else res[i]=st.top();

                st.push(i);
            }
        }
        return res;
    }
    int mod=1e9+7;
    int modPow(int x, int y)
    {
        if (y == 0)
            return 1;
        long p = modPow(x, y / 2) % mod;
        p = (p * p) % mod;
        return y % 2 ? (p * x) % mod : p;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int> all(1e5+1,0);
        for(int i=2;i<=1e5;i++){
            if(!all[i]){
                for(int j=i;j<=1e5;j+=i){
                    all[j]++;
                }
            }
        }
        int n=nums.size();
        vector<int> ps(n,0);
        for(int i=0;i<n;i++){
            ps[i]=all[nums[i]];
        }
        vector<int> ngl,ngr;
        ngl=getNGL(ps);
        ngr=getNGR(ps);

        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }

        sort(vec.rbegin(),vec.rend());
        long long res=1;
        // long long mod=1e9+7;
        for(int i=0;i<n;i++){
            int num=vec[i].first;
            int idx=vec[i].second;
            // now we will check contribution of this number 
            long long range=1L*(idx-ngl[idx])*(ngr[idx]-idx);
            int operation;
            if(k>range) operation=range;
            else operation=k;
            

            res=res%mod*modPow(num,operation)%mod;
            

            k-=operation;
            if(k==0) return (int)res;
        }
        return (int)res;

    }
};