class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // most optimised way we will update ans vector according first we will update it with prefix then we will update it with post fix 
        int n=nums.size();
        vector<int> ans(n,1);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i];
        }

        int right=1;
        for(int i=n-1;i>=0;i--){
            if(i>0) ans[i]=ans[i-1]*right;//left*right
            else ans[i]=1*right;//boundary pr hai to left ==1

            right=right*nums[i];//update right
        }
        return ans;
    }
};