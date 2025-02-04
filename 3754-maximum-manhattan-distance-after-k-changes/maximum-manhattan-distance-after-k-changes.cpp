class Solution {
public:
    int maxDistance(string s, int k) {
    int n=s.length();
    // we will check all the path NE, NW, SE,SW and
    // jidhr jane me jyda faida wo ans
    int ans=0;
    int currCnt=0;
    //NE
    int temp=k;
    for(int i=0;i<n;i++){
        if(s[i]=='N' || s[i]=='E') currCnt++;
        else if(temp>0){
            currCnt++;
            temp--;
        }
        else currCnt--;
        ans=max(ans,currCnt);
    }
    //NW
    temp=k;
    currCnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='N' || s[i]=='W') currCnt++;
        else if(temp>0){
            currCnt++;
            temp--;
        }
        else currCnt--;
        ans=max(ans,currCnt);
    }
    //SW
    temp=k;
    currCnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='S' || s[i]=='W') currCnt++;
        else if(temp>0){
            currCnt++;
            temp--;
        }
        else currCnt--;
        ans=max(ans,currCnt);
    }
    //SE
    temp=k;
    currCnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='S' || s[i]=='E') currCnt++;
        else if(temp>0){
            currCnt++;
            temp--;
        }
        else currCnt--;
        ans=max(ans,currCnt);
    }
    return ans;
    }
};