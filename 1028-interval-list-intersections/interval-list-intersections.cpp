class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        // space optimised and time optimised

        int lenFirst=firstList.size();
        int lenSecond=secondList.size();
        vector<vector<int>> ans;
        vector<int> temp(2);

        int firstPtr=0;
        int secondPtr=0;

        while(firstPtr<lenFirst && secondPtr<lenSecond){
            if(firstList[firstPtr][0]<=secondList[secondPtr][1] && secondList[secondPtr][0]<=firstList[firstPtr][1]){
                temp[0]=max(firstList[firstPtr][0],secondList[secondPtr][0]);
                temp[1]=min(firstList[firstPtr][1],secondList[secondPtr][1]);
                ans.push_back(temp);
            }
            if(firstList[firstPtr][1]>secondList[secondPtr][1]) secondPtr++;
            else firstPtr++;
        }
        return ans;
    }
};