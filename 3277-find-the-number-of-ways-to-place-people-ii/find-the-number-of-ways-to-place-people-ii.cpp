class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            // if x is same we need to sort y in decreasing order
            return a[1]>b[1];
        }
        return a[0]<b[0];//else sort by x
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int count=0;
        for(int i=0;i<points.size();i++){
            int cx=points[i][0];
            int cy=points[i][1];
            int minSoFar=INT_MAX;
            for(int j=i-1;j>=0;j--){
                if(points[j][1]>=cy){
                    if(points[j][1]<minSoFar){
                        count++;
                        minSoFar=points[j][1];
                    }
                }
            }
        }

        return count;
    }
};