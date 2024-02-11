class Solution {
public: 
    int solve(int i,int j1,int j2,vector<vector<int>> & grid,int n,int m,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m){
            return -1e9;
        }
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e9;
        // int dj[]={-1,0,1};
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2){
                    maxi=max(grid[i][j1]+solve(i+1,j1+dj1,j2+dj2,grid,n,m,dp),maxi);
                }
                else {
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+dj1,j2+dj2,grid,n,m,dp));
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m , -1)));

        // return solve(0,0,m-1,grid,n,m,dp);

        // tabulation
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m , 0)));

        // lets add base case we will go from n-1 to top
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2){
                    dp[n-1][j1][j2]=grid[n-1][j2];//if they both are at same position
                }
                else{
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        // base case done
        // now ab jo jo chngeing parameter hai utna loop chalega i,j1,j2 and uske ander jo recusion me kiye bss wohi krna hai


        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    // recusion copy paste part
                    int maxi=-1e9;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value=0;
                            if(j1==j2){
                                value=grid[i][j1];//if value same then add any one else add both
                            }
                            else value=grid[i][j1]+grid[i][j2];

                            if(j1+dj1>=0 && j2+dj2<m && j1+dj1<m && j2+dj2>=0){
                                value+=dp[i+1][j1+dj1][j2+dj2];
                            }
                            else value=-1e9;

                            maxi=max(value,maxi);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                    
                            
                            
                    }
                }
            }
        return dp[0][0][m-1];//return that jha se call gya tha

    }
};