class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;

        // agar n ko sirf 2 ,3 and 5 se divide krke 1 tk la skte hai it means it dont have anyfactors 
        // other than 2,3 and 5

        while(n%2==0) n=n/2;
        while(n%3==0) n=n/3;
        while(n%5==0) n=n/5;

        return n==1;
    }
};