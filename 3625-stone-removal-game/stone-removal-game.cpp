class Solution {
public:
    bool canAliceWin(int n) {
        int turn=10;
        bool alice=false;
        while(n>=turn){
            alice=!alice;
            n-=turn;
            turn--;
        }
        return alice;
    }
};