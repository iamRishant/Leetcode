class Solution {
public:
    bool solve(int index,vector<int> & arr, vector<int> & vis){
        if(arr[index]==0) return true;
        vis[index]=1;

            bool val=false;
        
            int npi=index+arr[index];
            int nni=index-arr[index];
            if(npi<arr.size() && !vis[npi]) val=(val || solve(npi,arr,vis));
            if(nni>=0 && !vis[nni]) val=(val || solve(nni,arr,vis));
            if(val==true) return true;
        
        return val;

    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);
        return solve(start,arr,vis);
    }
};