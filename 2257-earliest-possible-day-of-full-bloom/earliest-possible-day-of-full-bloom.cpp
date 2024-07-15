class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vec;

        for(int i=0;i<growTime.size();i++){
            vec.push_back({growTime[i],plantTime[i]});
        }
        sort(vec.rbegin(),vec.rend());
        int prevPlant=0;
        int maxi=-1;
        for(auto it: vec){
            prevPlant+=it.second;
            maxi=max(maxi,it.first+prevPlant);
        }

        return maxi;
    }
};