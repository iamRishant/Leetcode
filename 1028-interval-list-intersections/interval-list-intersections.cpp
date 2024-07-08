class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size()==0 || secondList.size()==0) return {};

        vector<vector<int>> ans;

        int i=0;
        int j=0;
        int n=firstList.size();
        int m=secondList.size();
        
        while(i<n && j<m){
            int flf=firstList[i][0];
            int fls=firstList[i][1];
            int slf=secondList[j][0];
            int sls=secondList[j][1];
            
            int a=max(flf,slf);
            int b=min(fls,sls);
            if(b>=a) ans.push_back({a,b});

            if(fls>sls){
                j++;
            }
            else if(sls>fls){
                i++;
            }
            else{
                i++;
                j++;
            }
        }
        return ans;
    }
};