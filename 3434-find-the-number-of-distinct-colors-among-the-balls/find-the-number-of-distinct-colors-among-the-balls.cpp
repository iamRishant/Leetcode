class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mp;
        map<int,int> s;
        // int n=queries.size();
        // vector<int>(limit+1,0);
        vector<int> ans;
        for(auto it:queries){
            int box=it[0];
            int color=it[1];

            // if box is untouched and unique color
            if(mp.find(box)==mp.end() && s.find(color)==s.end()){
                mp[box]=color;
                s[color]++;
            }
            else if(mp.find(box)!=mp.end()){
                // it means box has some color and we have to overwrite it
                int prevColor=mp[box];
                // we have to remove this color from map or decrease its freq
                s[prevColor]--;
                if(s[prevColor]==0) s.erase(prevColor);
                mp[box]=color;//new color updated
                s[color]++;
            }
            else{
                // it means new box but same color
                mp[box]=color;
                s[color]++;
            }
            ans.push_back(s.size());
            // for(auto it2:s) cout<<it2.first<<" "<<it2.second<<" ";
            // cout<<endl;
        }
        return ans;
        
    }
};