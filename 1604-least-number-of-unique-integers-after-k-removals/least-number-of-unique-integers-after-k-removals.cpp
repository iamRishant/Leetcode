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
        vector<pair<int,int>> p;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            p.push_back(make_pair(it.first,it.second));
        }
        sort(p.begin(),p.end(),compare);
        for(int i=0;i<p.size();i++){
            // cout<<p[i].first<<" "<<p[i].second<<endl;
            if(k==0){
                int ans=p.size()-(i);
                return ans;
            }
            if(p[i].second<=k) k-=p[i].second;
            else {
                int ans=(p.size()-i);
                return ans;
            }
        }


        return 0;
    }
};