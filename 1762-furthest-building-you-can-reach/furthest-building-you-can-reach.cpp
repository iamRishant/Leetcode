class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(;i<heights.size()-1;i++){
            int jumpLen=heights[i+1]-heights[i];
            if(jumpLen>0) pq.push(jumpLen);
            if(pq.size()>ladders){
                bricks-=pq.top();
                pq.pop();
            }
            if(bricks<0) return i;
        }
        return i;
    }
};