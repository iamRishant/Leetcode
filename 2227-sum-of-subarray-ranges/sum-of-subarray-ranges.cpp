class Solution {
public:
    vector<int> getNSL(vector<int> &arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;//we are putting index
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();//to avoid duplicates we use = in nsl and strict in nsr
                if(st.empty()) res[i]=-1;// it means no one is smaller than than arr[i] in left
                else res[i]=st.top();

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
                res[i]=n;//we are putting index
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]) st.pop();//to avoid duplicates we use = in nsl and strict in nsr
                if(st.empty()) res[i]=n;// it means no one is smaller than than arr[i] in left
                else res[i]=st.top();

            }
            st.push(i);
        }
        return res;
    }
    vector<int> getNGR(vector<int> &arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=n;//we are putting index
            }
            else{
                while(!st.empty() && arr[st.top()]<arr[i]) st.pop();//to avoid duplicates we use = in nsl and strict in nsr
                if(st.empty()) res[i]=n;// it means no one is smaller than than arr[i] in left
                else res[i]=st.top();

            }
            st.push(i);
        }
        return res;
    }
    vector<int> getNGL(vector<int> &arr,int n){
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i]=-1;//we are putting index
            }
            else{
                while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();//to avoid duplicates we use = in nsl and strict in nsr
                if(st.empty()) res[i]=-1;// it means no one is smaller than than arr[i] in left
                else res[i]=st.top();

            }
            st.push(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& arr) {
        // subarrayRange = Subarraylargest-subarrayminimum
        // here we need to find all the NSL NSR NGL NGR
        int n=arr.size();
        vector<int> NSL=getNSL(arr,n);
        vector<int> NGL=getNGL(arr,n);
        vector<int> NSR=getNSR(arr,n);
        vector<int> NGR=getNGR(arr,n);
        long long largest=0;
        long long smallest=0;
        for(int i=0;i<n;i++){
            int lss=i-NSL[i];
            int rss=NSR[i]-i;
            int lll=i-NGL[i];
            int rrr=NGR[i]-i;
            long long totalSubSmall=lss*rss;
            long long totalSubLarge=lll*rrr;
            largest+=(totalSubLarge*arr[i]);
            smallest+=(totalSubSmall*arr[i]);
        }
        return largest-smallest;
    }
};