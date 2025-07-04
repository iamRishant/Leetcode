class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';

        long long len=1;
        int n=operations.size();
        long long newK=-1;
        int currOperation=-1;

        for(int i=0;i<n;i++){
            len=len*2;
            if(len>=k){
                newK=k-(len/2);
                currOperation=operations[i];
                break;
            }
        }
        char ch=kthCharacter(newK, operations);

        if(currOperation==0) return ch;
        return ch=='z'?'a': ch+1;
    }
};