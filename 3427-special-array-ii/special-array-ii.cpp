class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n=nums.size();
        vector<int> preFix(n+1,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                preFix[i]=1;
            }
            else preFix[i]=0;

            preFix[i]+=preFix[i-1];
        }

        for(int i=0;i<queries.size();i++){
            if((preFix[queries[i][1]]-preFix[queries[i][0]])==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

    }
};