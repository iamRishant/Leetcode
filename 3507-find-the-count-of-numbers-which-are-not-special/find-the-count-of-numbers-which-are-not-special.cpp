class Solution {
public:
    vector<int> Prime(int n){
            vector<int> primeArray(n+1,1);
            primeArray[0]=0;
            primeArray[1]=0;
            for(int i=2;i<=n;i++){
                if(primeArray[i]==1){
                    for(int j=i*i;j<=n;j+=i){
                        primeArray[j]=0;
                    }
                }
            }
            return primeArray;
            // to find number prime numbers in range u need to use prefix sum
        }
    int nonSpecialCount(int l, int r) {
        int left=sqrt(l);
        if(left*left!=l) left++;
        int right=sqrt(r);
        if(right*right!=r) right++;
        vector<int> preFix=Prime(right);
        int countOfSpecial=0;
        for(int i=0;i<=right;i++){
            if(preFix[i]){
                // cout<<i<<" ";
                if(i*i>=l && i*i<=r) countOfSpecial++;
            }
        }
        return (r-l+1)-countOfSpecial;
    }
};