class Solution {
public:
    int solveLower(int si,int sj,int ei,int ej,vector<vector<int>> &fruits,int n,vector<vector<int>> &dp1){
        if(si==n || sj==n) return -1e5;
        if(si==sj) return -1e5;
        if(si==ei && sj==ej) return fruits[si][sj];

        if(dp1[si][sj]!=-1) return dp1[si][sj];

        int p1=fruits[si][sj]+solveLower(si-1,sj+1,ei,ej,fruits,n,dp1);
        int p2=fruits[si][sj]+solveLower(si,sj+1,ei,ej,fruits,n,dp1);
        int p3=fruits[si][sj];
        if(si+1<n) p3+=solveLower(si+1,sj+1,ei,ej,fruits,n,dp1);

        return dp1[si][sj] =max(p1,max(p2,p3));
    }
    int solveUpper(int si,int sj,int ei,int ej,vector<vector<int>> &fruits,int n,vector<vector<int>> &dp2){
        if(si==n || sj==n) return -1e5;
        if(si==sj) return -1e5;
        if(si==ei && sj==ej) return fruits[si][sj];
        if(dp2[si][sj]!=-1) return dp2[si][sj];

        int p1=fruits[si][sj]+solveUpper(si+1,sj-1,ei,ej,fruits,n,dp2);
        int p2=fruits[si][sj]+solveUpper(si+1,sj,ei,ej,fruits,n,dp2);
        int p3=fruits[si][sj];
        if(sj+1<n) p3+=solveUpper(si+1,sj+1,ei,ej,fruits,n,dp2);

        return dp2[si][sj]= max(p1,max(p2,p3));
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int firstChild=0;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    firstChild+=fruits[i][j];
                }
            }
        }
        int secondChild=0;
        int thirdChild=0;
        int si=n-1;
        int sj=0;
        int ei=n-2;
        int ej=n-2;
        vector<vector<int>> dp1(n+1,vector<int> (n+1,-1));
        secondChild=solveLower(si,sj,ei,ej,fruits,n,dp1);
        vector<vector<int>> dp2(n+1,vector<int> (n+1,-1));
        thirdChild=solveUpper(0,n-1,ei,ej,fruits,n,dp2);

        return firstChild+secondChild+thirdChild;
    }
};