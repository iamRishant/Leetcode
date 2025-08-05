class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int maxi=0;
        int n=fruits.size();
        int sum=0;
        int ans=0;
        map<int,int> mp;
        
        while(r<n){
            mp[fruits[r]]++;
            while(l<r && mp.size()>2){
                mp[fruits[l]]--;
                sum-=fruits[l];

                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            // sum+=fruits[r];
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};