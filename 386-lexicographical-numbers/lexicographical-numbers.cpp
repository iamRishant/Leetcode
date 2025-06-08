class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int currNumber=1;
        for(int i=0;i<n;i++){// how many times loop run depend on numner of number which is n
            ans.push_back(currNumber);
            if(currNumber*10<=n){
                currNumber*=10;
            }
            else{
                while(currNumber%10==9 || currNumber>=n) currNumber=currNumber/=10;
                currNumber+=1;
            }
        }
        return ans;
    }
};