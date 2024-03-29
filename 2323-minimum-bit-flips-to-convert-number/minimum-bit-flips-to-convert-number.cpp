class Solution {
public:
    int minBitFlips(int start, int goal) {
        // int tot=0;
        // int alpha=max(start,goal);
        // while(alpha>0){
        //     tot++;
        //     alpha/=2;
        // }

        // int flip=(start ^ goal);
        // // flip=(~flip);
        // int count=0;
        // // cout<<flip<<endl;
        // // int tot=0;x
        // while(tot--){
        //     // tot++;
        //     if((flip&1)==1) count++;
        //     flip=flip/2;
        // }
        // // return tot-count;

        // return count;
        return __builtin_popcount(start^goal);
    }
};