class Solution {
public:
    int isPrime(int n){
        if(n<=1) return false;

        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int delrow[]={0,1,1,1,0,-1,-1,-1};
        int delcol[]={1,1,0,-1,-1,-1,0,1};
        map<int,int> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                for(int k=0;k<8;k++){
                    int row=i;
                    int col=j;
                    int num=mat[row][col];
                        
                    while(true){
                        row=row+delrow[k];
                        col=col+delcol[k];
                        if(row<0 || col<0 || row>=mat.size() || col>=mat[0].size()) break;
                        num=num*10+mat[row][col];
                        if(isPrime(num)) mp[num]++;
                    }
                }
            }
        }
        if(mp.empty()==true) return -1;
        int ans=0;
        int freq=0;
        for(auto [k,v]:mp){
            if(v>=freq){
                freq=v;
                ans=k;
            }
        }
        return ans;
    }
};