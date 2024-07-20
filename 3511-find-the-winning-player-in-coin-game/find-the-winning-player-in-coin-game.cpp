class Solution {
public:
    string losingPlayer(int x, int y) {
        string s="Bob";
        bool flag=true;
        while(x>=1 && y>=4){
            x-=1;
            y-=4;
            if(flag){
                s="Alice";
            }
            else s="Bob";
            flag=!flag;
        }
        return s;
    }
};