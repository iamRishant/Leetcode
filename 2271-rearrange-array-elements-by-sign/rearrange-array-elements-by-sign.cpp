class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N=nums.size();
        vector<int> ans;
        int p=0;
        int n=0;
        
        while(p<N && n<N){
            while(p<N && nums[p]<0) p++;
            while(n<N && nums[n]>0) n++;
            if(p<N && n<N){
                ans.push_back(nums[p]);
                ans.push_back(nums[n]);
            }
            p++;
            n++;
        }
        return ans;


        
    }
};