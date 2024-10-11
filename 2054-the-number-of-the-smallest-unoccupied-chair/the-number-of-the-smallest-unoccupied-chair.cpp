class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int at=times[targetFriend][0];
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        priority_queue<int,vector<int>, greater<int>> chairs;

        int maxC=0; 
        sort(times.begin(),times.end());


        for(int i=0;i<times.size();i++){

            // first we will check that how much free chair we have 
            while(!pq.empty() && pq.top().first<=times[i][0]){
                chairs.push(pq.top().second);
                pq.pop();
            }

            if(chairs.empty()){
                //first lets check if it is desired index;
                if(at==times[i][0]) return maxC;//since we dont have free chairs
                // ab free chair to hai nhi so we need to give new chair to arrival

                pq.push({times[i][1],maxC});//leaving time , chair
                maxC++;
            }
            else{
                // it means we have free chair
                // smallest free chair
                auto x=chairs.top();
                chairs.pop();
                if(at==times[i][0]) return x;
                pq.push({times[i][1],x});
            }
        }
        return -1;
        
    }
};