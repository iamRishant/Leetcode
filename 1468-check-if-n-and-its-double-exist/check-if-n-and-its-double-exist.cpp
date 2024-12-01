class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++) mp[arr[i]]=i;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i]*2)!=mp.end() && i!=mp[arr[i]*2]) return true;
        }
        return false;
    }
};