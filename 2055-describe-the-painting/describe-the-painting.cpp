class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> preFix;
        for(int i=0;i<segments.size();i++){
            int start=segments[i][0];
            int end=segments[i][1];
            preFix[start]+=segments[i][2];
            preFix[end]-=segments[i][2];
        }
        long long color=0;
        int prev=-1;
        vector<vector<long long>> ans;
        for(auto it:preFix){
            if(prev!=-1 && color!=0){
                ans.push_back({prev,it.first,color});
            }
            color+=it.second;
            prev=it.first;
        }
        return ans;
    }
};