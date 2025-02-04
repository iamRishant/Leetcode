class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps(1,startTime[0]);//pushing first gap

        for(int i=1;i<startTime.size();i++){
            int gap=startTime[i]-endTime[i-1];
            gaps.push_back(gap);
        }
        // pushing last gap
        gaps.push_back(eventTime-endTime.back());
        
        // if we can shift k meeting 
        //it means we can manipulate k+1 gaps
        // and since we cannot change the order
        // these gaps should be consecutive
        int currSum=0;
        int maxSum=0;
        for(int i=0;i<gaps.size();i++){
            currSum+=gaps[i];
            if(i-(k+1)>=0) currSum-=gaps[i-k-1];
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};