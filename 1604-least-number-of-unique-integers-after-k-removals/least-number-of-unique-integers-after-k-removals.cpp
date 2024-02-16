class Solution {
public:
    static bool compare(pair<int,int> &p1,
            pair<int, int> &p2)
{
    // If frequencies are same, compare
    // values
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        // no need to take the pair 
        vector<int> v;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            // cout<<p[i].first<<" "<<p[i].second<<endl;
            if(k==0){
                int ans=v.size()-(i);
                return ans;
            }
            if(v[i]<=k) k-=v[i];
            else {
                int ans=(v.size()-i);
                return ans;
            }
        }


        return 0;
    }
};