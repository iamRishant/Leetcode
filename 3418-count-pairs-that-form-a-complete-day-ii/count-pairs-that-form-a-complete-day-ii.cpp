class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        map<int ,int > mp;
        for(int i=0;i<n;i++){
            hours[i]=hours[i]%24;
            mp[hours[i]]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int toFind=24-hours[i];
            mp[hours[i]]--;
            if(mp[hours[i]]==0) mp.erase(hours[i]);
            // now two cases if hours[i]==0
            if(hours[i]==0){
                ans+=mp[hours[i]];
            }
            else if(mp.find(toFind)!=mp.end()){
                ans+=mp[toFind];
            }
        }
        return ans;

    }
};