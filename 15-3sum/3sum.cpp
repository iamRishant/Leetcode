class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // one method is n^3
        // 2nd method is n^2 log n with set data structure
        // 3rd is using 3 poitners

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;//case of duplicacy

            int j=i+1;
            int k=n-1;
            while(k>j){
                int tot=nums[i]+nums[j]+nums[k];
                if(tot<0) j++;
                else if(tot>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    // now since we dont need duplicates we can just simply move
                    int left=nums[j];
                    int right=nums[k];
                    while(j<k && nums[j]==left) j++;
                    while(j<k && nums[k]==right) k--; 
                }
            }

        }

        return ans;
    }
};