class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int> pre(n),suff(n);
        int currProd=1;
        for(int i=0;i<n;i++){
            pre[i]=currProd*nums[i];
            currProd=pre[i];
        }
        vector<int> ans(n);
        currProd=1;
        for(int i=n-1;i>=0;i--){
            int left=1;
            if(i>0) left=pre[i-1];
            ans[i]=left*currProd;
            currProd*=nums[i];
        }
        return ans;
    }
};