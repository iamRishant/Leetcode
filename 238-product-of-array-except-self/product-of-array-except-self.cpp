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
        currProd=1;
        int ind=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=currProd*nums[i];
            currProd=suff[i];
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int left=1;
            int right=1;
            if(i>0) left=pre[i-1];
            if(i<n-1) right=suff[i+1];
            ans[i]=left*right;
        }
        return ans;
    }
};