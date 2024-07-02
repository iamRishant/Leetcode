class Solution {
public:
    int candy(vector<int>& ratings) {
        map<pair<int,int>,int> mp;
        int n=ratings.size();
        for(int i=0;i<n;i++){
            mp[{ratings[i],i}]++;
        }
        vector<int> ans(n,1);
        for(auto it: mp){
            int currRating=it.first.first;
            int idxRating=it.first.second;
            if(idxRating-1>=0 && ratings[idxRating-1]>currRating){
                // ans[idxRating-1]=ans[idxRating]+1;
                ans[idxRating-1]=max(ans[idxRating-1],ans[idxRating]+1);
            }
            if(idxRating+1<n && ratings[idxRating+1]>currRating){
                ans[idxRating+1]=max(ans[idxRating+1],ans[idxRating]+1);
            }
            // mp.erase(mp.find());
        }

        return accumulate(ans.begin(),ans.end(),0);
    }
};