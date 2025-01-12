class Solution {
public:
    bool canBeValid(string s, string locked) {
        int wild=0;
        int open=0;
        int close=0;


        int n=s.length();
        if(n%2==1) return false;
        for(int i=0;i<n;i++){
            if(locked[i]=='0') wild++;
            else if(s[i]=='(') open++;
            else if(s[i]==')') close++;

            if(wild+open<close) return false;
        }
        wild=0;
        open=0;
        close=0;

         for(int i=n-1;i>=0;i--){
            if(locked[i]=='0') wild++;
            else if(s[i]=='(') open++;
            else if(s[i]==')') close++;

            if(wild+close<open) return false;
        }
        return true;

    }
};