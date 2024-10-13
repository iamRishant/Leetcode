class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==2) ans.push_back(-1);
            else{
                int num=1;
                int k=0;
                while((num) & nums[i]){
                    k++;
                    num=(1<<k);
                }
                // num=(num>>1);
                // cout<<num<<endl;
                // cout<<(num>>1)<<endl;
                // cout<<endl;
                // num=(~(num));
                int curr=(nums[i] & ~(num>>1));
                ans.push_back(curr);
            }
        }
        return ans;
    }
};