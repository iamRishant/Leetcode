class Solution {
public:
    vector<int> getngr(vector<int> &ps){
        stack<int> st;
        int n=ps.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=n;
                st.push(i);
            }
            else{
                while(!st.empty() && ps[st.top()]<=ps[i]) st.pop();
                if(st.empty()) ans[i]=n;
                else ans[i]=st.top();

                st.push(i);

            }
        }
        return ans;
    }
    vector<int> getngl(vector<int> &ps){
        stack<int> st;
        int n=ps.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            if(st.empty()){
                ans[i]=-1;
                st.push(i);
            }
            else{
                while(!st.empty() && ps[st.top()]<ps[i]) st.pop();
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();

                st.push(i);

            }
        }
        return ans;
    }
    int modPow(int num,int power){
        int mod=1e9+7;
        
        if(power==0) return 1;
        long long p=modPow(num,power/2)%mod;
        p=(p*p)%mod;

        return power%2 ? (p*num)%mod: p;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int> all(1e5+1,0);
        for(int i=2;i<=1e5;i++){
            if(!all[i]){
                for(int j=i;j<1e5;j+=i){
                    all[j]++;
                }
            }
        }
        int n=nums.size();
        vector<int> ps(n,0);
        for(int i=0;i<n;i++) ps[i]=all[nums[i]];
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++) vec.push_back({nums[i],i});
        sort(vec.rbegin(),vec.rend());
        vector<int> ngl,ngr;
        ngl=getngl(ps);
        ngr=getngr(ps);
        long long ans=1;
        int mod=1e9+7;

        for(int i=0;i<n;i++){
            int num=vec[i].first;
            int idx=vec[i].second;

            long long contribution=1L*(idx-ngl[idx])*(ngr[idx]-idx);
            int operation;
            if(contribution > k) operation=k;
            else operation=contribution;

            ans=ans%mod*modPow(num,operation)%mod;
            // ans=ans%mod;

            k-=operation;
            if(k==0) return (int)ans;
        }
        return ans;
    }
};