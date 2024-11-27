class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> preFix(n+1,0);
        for(auto it:queries){
            preFix[it[0]]++;
            preFix[it[1]+1]--;
        }
        for(int i=1;i<=n;i++) preFix[i]+=preFix[i-1];
        for(int i=0;i<n;i++){
            if(preFix[i]-nums[i]<0) return false;
        }
        return true;
    }
};