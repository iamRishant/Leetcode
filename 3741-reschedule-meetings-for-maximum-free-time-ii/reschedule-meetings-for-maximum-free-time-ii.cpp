class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
         vector<int> gaps(1,startTime[0]);

        for(int i=1;i<startTime.size();i++){
            int gap=startTime[i]-endTime[i-1];
            gaps.push_back(gap);
        }
       
        gaps.push_back(eventTime-endTime.back());
        
        // since we can shift to left prefix max and suffix max also we need to create it
        vector<int> prefixMax (gaps.size(),0);
        vector<int> suffixMax (gaps.size(),0);
        int maxi=0;
        for(int i=0;i<gaps.size();i++){
            prefixMax[i]=maxi;
            maxi=max(gaps[i],maxi);
        }
        maxi=0;
        for(int i=gaps.size()-1;i>=0;i--){
            suffixMax[i]=maxi;
            maxi=max(gaps[i],maxi);
        }

        // now we have to iterate over meetings and check if it can adjust left 
        //or right
        int ans=0;//we will calculate gap1+meeting(if it can go left or right)+gap2
        for(int i=0;i<gaps.size()-1;i++){
            int sum=gaps[i]+gaps[i+1];
            int meetingLength=endTime[i]-startTime[i];
            if(meetingLength<=suffixMax[i+1] || meetingLength<=prefixMax[i]) sum+=meetingLength;
            ans=max(ans,sum);
        }
        
        return ans;
    }
};